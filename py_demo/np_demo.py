#!D:\Python27\python.exe
import cv2
import numpy as np

def demo_1():
    a =[1,2,3,4,5,6,7,8,9]
    print a
    arr = np.array(a)
    
    print arr
    print arr.shape
    print("====array 1x9====")
    arr.shape = (1,9)
    print arr
    print("====array 3x3====")
    arr.shape = (3,3)
    print arr
##数据类型
    print arr.dtype
##所有数据类型
    print set(np.typeDict.values())

def demo_2():
    arr = np.arange(0, 10, 1)
    print arr

    arr = np.linspace(0, 1, 10, endpoint = False)
    print arr

    arr = np.logspace(0, 8, 9, base = 2, endpoint = True)
    print arr
    print arr.dtype

    arr = np.zeros((2,3))
    print arr


if __name__ == '__main__':
    demo_2()
    

    
