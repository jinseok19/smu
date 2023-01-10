import tkinter
import cv2
import PIL.Image, PIL.ImageTk
import datetime

class App:
  def __init__(self, window, window_title, video_source = 0):
    self.window = window
    self.window.title(window_title)
    self.video_source = video_source
    self.is_recording = False
    
    self.vid = MyVideoCapture(self.video_source)
    
    self.canvas = tkinter.Canvas(window, width = self.vid.width, height = self.vid.height)
    self.canvas.pack()
    
    self.btn_snapshot = tkinter.Button(window, text = "녹화 시작", width= 20, height=5, command = self.record)
    self.btn_snapshot.pack(anchor = tkinter.CENTER, expand = True)
    
    self.fps = self.vid.webcam.get(cv2.CAP_PROP_FPS)
    self.delay = round(1000.0/self.fps)
    self.update()
    
    self.window.mainloop()
    
  def record(self):
      
      self.is_recording = ~self.is_recording
      
      if self.is_recording:
        self.vid.create_video(self.fps)
        self.btn_snapshot.config(text = "녹화중단")
        
      else:
        self.vid.video.release()
        self.btn_snapshot.config(text = "녹화시작")
        
  def update(self):

      ret, frame = self.vid.get_frame()
      
      if ret:
        
        if self.is_recording:
          self.vid.video.write(frame)
          
        self.photo = PIL.ImageTK.PhotoImage(image = PIL.Image.fromarray(cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)))
        self.canvas.create_image(0,0, image = self.photo, anchor = tkinter.NW)
      self.window.after(self.delay, self.update)
      
  def __del__(self):
    if self.is_recording:
      self.vid.video.release()
    
class MyVideoCapture:
  def __init__(self, video_source =0):
    
    self.webcam = cv2.VideoCapture(video_source)
    if not self.webcam.isOpened():
      raise ValueError("Unable to open video source", video_source)
    
  def create_video(self, fps):
    file_name = str(datetime.datetime.now()) + '.mp4'
    
    fourcc = cv2.VideoWriter_fourcc(*'mp4v')
    
    self.video = cv2.VideoWriter(file_name, fourcc, fps/3.0, (self.width, self.height))
    
  
  def get_frame(self):
    if self.webcam.isOpened():
      font_color = (255,255,255)
      ret, frame = self.webcam.read()
      if ret:
        frame = cv2.flip(frame, 1)
        
        font = cv2.FONT_HERSHEY_SCRIPT_COMPLEX
        
        dt = str(datetime.datetime.now())
        
        frame = cv2.putText(frame, dt, (30,60), font, 1, font_color, 4, cv2.LINE_AA)
        
        return (ret, frame)
      else:
        return (ret, None)
    else:
      return (False, None)    
    
  def __del__(self):
    if self.webcam.isOpened():
      self.webcam.release()
      
App(tkinter.Tk(), "Tkinter and OpenCV")

         
    