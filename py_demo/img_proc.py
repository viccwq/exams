#!D:\Python34\python.exe
import cv2
import numpy as np


if __name__ == '__main__':

    import sys

    if len(sys.argv)>1:
        im = cv2.imread(sys.argv[1])
    else :
        im = cv2.imread('../cpp/lena.jpg')
        print "usage : python img_proc.py <image_file>"


    gray = cv2.cvtColor(im,cv2.COLOR_BGR2GRAY)


    print ''' Histogram plotting \n
    Keymap :\n
    a - show histogram for color image in curve mode \n
    b - show histogram in bin mode \n
    c - show equalized histogram (always in bin mode) \n
    d - show histogram for color image in curve mode \n
    e - show histogram for a normalized image in curve mode \n
    Esc - exit \n
    '''

    cv2.imshow('image',im)
    while True:
        k = cv2.waitKey(0)&0xFF
        if k == ord('r'):
            height, width = gray.shape[0:2]
            print height
            print width
            res=cv2.resize(gray,(width,550),interpolation=cv2.INTER_CUBIC)
            cv2.imshow('resize',res)
            cv2.imwrite('resize.bmp',res)
            print 'r'
        elif k == ord('b'):
            print 'b'
            lines = hist_lines(im)
            cv2.imshow('histogram',lines)
            cv2.imshow('image',gray)
        elif k == 27:
            print 'ESC'
            cv2.destroyAllWindows()
            break
    cv2.destroyAllWindows()
