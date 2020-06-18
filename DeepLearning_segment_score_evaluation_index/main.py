import cv2

# 混淆矩阵
#    1   0
# 1  TP  FP
# 0  FN  TN
def cal(binary_GT,binary_R):
    row, col = binary_GT.shape  # 矩阵的行与列
    TP,TN,FP,FN = 0, 0, 0, 0
    for i in range(row):
        for j in range(col):
            if binary_GT[i][j] == 255 and binary_R[i][j] == 255:
                TP  += 1;
            if binary_GT[i][j] == 255 and binary_R[i][j] == 0:
                FN += 1
            if binary_GT[i][j] == 0 and binary_R[i][j] == 255:
                FP += 1
            if binary_GT[i][j] == 0 and binary_R[i][j] == 0:
                TN += 1
    # print(TP,FN,FP,TN)
    print('PA Acc计算结果，      Acc       = {0:.4}'.format((TP+TN)/(TP+TN+FP+FN)))
    print('Precision计算结果，      Precision       = {0:.4}'.format(TP/ (TP + FP)))
    print('斑块IoU计算结果，= {0:.4}'.format(TP / (TP + FP + FN)))
    print('MIoU计算结果，= {0:.4}'.format(TP/(TP + FP + FN) + TN/(TN + FN + FP)/2))
    print('Recall计算结果，= {0:.4}'.format(TP/(TP + FN)))
    print('acc 斑块类计算结果，      Acc       = {0:.4}'.format(TP / (TP + FN)))

    P = TP/ (TP + FP)
    R = TP/(TP + FN)
    F1 = 2*P*R/(P+R)
    print('F1，          = {0:.4}'.format(F1))

if __name__ == '__main__':
    # step 1：读入图像，并灰度化
    img_GT = cv2.imread(r'C:\Users\win10\Desktop\coronary\data\train\label\1.png',0)
    img_R  = cv2.imread(r'C:\Users\win10\Desktop\just_test\1_predict.png',0)
    # imgray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)   # 灰度化
    # img_GT = img_GT[:,:,[2, 1, 0]]
    # img_R  = img_R[:,: [2, 1, 0]]

    # step2：二值化
    # 利用大律法,全局自适应阈值 参数0可改为任意数字但不起作用
    ret_GT, binary_GT = cv2.threshold(img_GT, 0, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)
    ret_R, binary_R   = cv2.threshold(img_R, 0, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)

    cal(binary_GT, binary_R)
