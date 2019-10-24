import time
import webbrowser


total_break = int(input('How many breaks do you want to take ? :: '))
free_time = 5 * 60
break_time = float(input("After what interval(in minutes) you want to take break? :: "))
break_time_in_sec = (break_time * 60) 

lists = ["https://youtu.be/SlPhMPnQ58k","https://youtu.be/_kqQDCxRCzM","https://youtu.be/BiVyN2ftrrs",
         "https://youtu.be/Ps4aVpIESkc","https://youtu.be/KfXvjxbRhZk"]

break_count = 0     
while (break_count < total_break):
    time.sleep(break_time_in_sec)
    webbrowser.open(lists[break_count%len(lists)])
    time.sleep(free_time)
    break_count += 1
