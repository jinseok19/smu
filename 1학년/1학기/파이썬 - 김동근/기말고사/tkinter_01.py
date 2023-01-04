from tkinter import *
from tkinter import messagebox

def button_action():
  messagebox.showinfo("버튼1","버튼이 눌림")
root = Tk()
root.title("RWT")
root.geometry("640x480")
root.resizable(False, False)

label = Label(root, text="hello world")
label.pack()

button1 = Button(root, text="버튼1",command = button_action)
button1.pack()

Entry1 = Entry(root)
Entry1.pack()
root.mainloop()

