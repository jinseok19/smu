import turtle as t


  
color_list = ['red', 'green', 'blue', 'yellow']

t.shape('turtle')
t.width(10)

for i in color_list:
    t.color(i)
    t.begin_fill()
    t.forward(100)
    t.lt(90)
    t.end_fill()



t.mainloop()
