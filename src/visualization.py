from tkinter import *
import tkinter as tk
from tkinter.ttk import Progressbar
from time import sleep
import random
import math
from pynput.mouse import Listener

WIDTH = 2440
HEIGHT = 1300

window = Tk()
canvas = Canvas(window, width=WIDTH, height=HEIGHT, bg="white")
canvas.pack()

class Room:
    def __init__(self, x, y, name, size, color, canvas, isstart):
        self.x = int(x)
        self.y = int(y)
        self.isstart = isstart
        self.name = name
        self.size = size
        self.color = color
        self.canvas = canvas
        self.children = []
        # This is what enables using the mouse:
        self.canvas.bind("<ButtonPress-1>", self.move_start)
        self.canvas.bind("<B1-Motion>", self.move_move)

    def draw(self):
        self.canvas.create_oval(self.x, self.y, self.size+self.x, self.size+self.y, fill=self.color, outline="")
    def add(self, child):
        self.children.append(child)
    #move
    def move_start(self, event):
        self.canvas.scan_mark(event.x, event.y)
    def move_move(self, event):
        self.canvas.scan_dragto(event.x, event.y, gain=1)


toggle = []
b = []
for line in sys.stdin:
    a = line.split(" ")
    if  (a[0][0] == '-'):
        break
    if a[0] == "Error":
        sys.exit()
    if (len(a) > 4):
        b.append(Room(int(a[2]), int(a[3]),a[1], int(a[0]), "#6c7a89", canvas, int(a[4])))
LINESIZE = int(18-pow(math.log(len(b), 2), 1.2))
if LINESIZE < 1:
    LINESIZE = 1

edges = []
paths = []
toggle = [False]
for line in sys.stdin:
    if (line[0] == '-'):
        break
    edges.append(line)

for line in sys.stdin:
    if (line[0] == '-'):
        break
    paths.append(line)
def draw_nodes():
    for x in b:
        if (x.isstart == 1):
            x.color = "#a537fd"
        elif (x.isstart == 2):
            x.color = "#f5e51b"
        else:
            x.color = "#6c7a89"
        x.draw()
        if (toggle[0]):
            canvas.update()
            sleep(.0005)
def draw_lines(edges):
    for line in edges:
        a = line.split(" ")
        i = 1
        for x in b:
            if x.name == a[0]:
                xx = x.x + x.size/2
                yy = x.y + x.size/2
                break
        if (len(a) > 1):
            while (i < len(a)):
                for x in b:
                    if (x.name == a[i]):
                        lx = x.x + x.size/2
                        ly = x.y + x.size/2
                        break
                canvas.create_line(xx,yy, lx,ly, fill="#bdc3c7", width=LINESIZE)
                if (toggle[0]):
                    canvas.update()
                    sleep(.0005)
                i += 1

#color = ["#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])]
colors = ["#FF9671", "#00C9A7", "#00D2FC", "#845EC2", "#FD94D0", "#2AF4FF", "#AB762C", "#f6ef98", "#f30cd4", "#ff9776", "#22b9ca"]

def draw_paths(paths):
    for line in paths:
        a = line.split(" ")
        i = 0
        color = random.choice(colors)
        if (len(a) > 1):
            while i < len(a) - 1:
                for x in b:
                    if (x.name == a[i]):
                        lx = x.x + x.size/2
                        ly = x.y + x.size/2
                        y = x
                        break
                for x in b:
                    if (x.name == a[i + 1]):
                        xx = x.x + x.size/2
                        xy = x.y + x.size/2
                        z = x
                        break
                canvas.create_line(lx,ly, xx,xy, fill=color, width=LINESIZE+LINESIZE/2)
                if toggle[0]:
                    canvas.update()
                    sleep(.000001)
                i += 1
                y.color = color
                z.color = color
                y.draw()
                z.draw()
m = [999999, 99999, -1, -1]
m = [2]
def bt(event):
    canvas.delete("all")
    canvas.create_text(2300, 1250, fill="black", font="Arial",text="By Zack & Jalal", anchor=NW)
    if  m[0] == 1:
        draw_paths(paths)
        m[0] = 2
    elif m[0] == 2:
        draw_lines(edges)
        draw_nodes()
        m[0] = 3
    else:
        draw_lines(edges)
        draw_nodes()
        draw_paths(paths)
        m[0] = 1
def but():
    if (toggle[0]):
        button["text"] = "off"
        toggle[0] = False
    else:
        button["text"] = "on"
        toggle[0] = True
button = Button(window, text="off", command=but)
button.place(relx=0.5, y=10, anchor=N)
canvas.bind("<Button-2>", bt)
# title
window.title("Lem-in | 1337")
# Signature
canvas.create_text(2300, 1250, fill="black", font="Arial",text="By Zack & Jalal", anchor=NW)
canvas.update()
window.mainloop()
