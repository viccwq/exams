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

def func3(i,j):
    return (i+1)*(j+1)
def demo_3():
    arr = np.fromfunction(func2, (9,4))
    print arr

#存取元素
def demo_4():
    arr = np.arange(10, 0, -1)
    print arr
    #取元素   
    print arr[0]
    print arr[1:3]
    print arr[:3]    
    #存元素    
    arr[1:3] = 100,200
    print arr
    #通过切片产生的新数组arr_1和原数组共享同一块存储空间
    arr_1 = arr[1:3]
    arr_1[0] = 500
    print arr
    #通过切片产生的新数组arr_2和原数组独立空间
    arr_2 = arr[[1,2]]
    arr_2[0] = 600
    print arr
    
    
    #int数组作为下标
    print "int数组作为下标"
    arr = np.arange(10, 0, -1)
    print arr[np.array([0,0,1,-1])]
    #bool数组作为下标
    print "bool数组作为下标"
    arr = np.arange(5, 0, -1)
    print arr[np.array([False,True, False, True, False])]



if __name__ == '__main__':
    demo_4()
    

    
