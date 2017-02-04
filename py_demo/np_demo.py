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
    ##��������
    print arr.dtype
    ##������������
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

#��ȡԪ��
def demo_4():
    arr = np.arange(10, 0, -1)
    print arr
    #ȡԪ��   
    print arr[0]
    print arr[1:3]
    print arr[:3]    
    #��Ԫ��    
    arr[1:3] = 100,200
    print arr
    #ͨ����Ƭ������������arr_1��ԭ���鹲��ͬһ��洢�ռ�
    arr_1 = arr[1:3]
    arr_1[0] = 500
    print arr
    #ͨ����Ƭ������������arr_2��ԭ��������ռ�
    arr_2 = arr[[1,2]]
    arr_2[0] = 600
    print arr
    
    
    #int������Ϊ�±�
    print "int������Ϊ�±�"
    arr = np.arange(10, 0, -1)
    print arr[np.array([0,0,1,-1])]
    #bool������Ϊ�±�
    print "bool������Ϊ�±�"
    arr = np.arange(5, 0, -1)
    print arr[np.array([False,True, False, True, False])]



if __name__ == '__main__':
    demo_4()
    

    
