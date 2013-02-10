//
//  MergeSort.c
//  AlgorithmHomework
//
//  Created by Haewon Kwak on 13-02-10.
//  Copyright (c) 2013 Haewon Kwak. All rights reserved.
//

#include <stdio.h>

void mergeSort(int a[], int left, int right);
void merge(int a[], int left, int mid, int right);

void mergeSort(int a[], int left, int right) {
    if (right-left>0) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

void merge(int a[],int left, int mid, int right){
    int tmpSize1=mid-left+1;
    int tmpSize2=right-mid;
    
    int tmpA[tmpSize1];
    int tmpB[tmpSize2];
    
    for(int l=0;l<tmpSize1;l++)
        tmpA[l]=a[left+l];
    for(int r=0;r<tmpSize2;r++){
        tmpB[r]=a[mid+1+r];
    }
    int i=0;
    int j=0;
    for (int k=left;k<=right;k++){
        if(i>=tmpSize1){
            a[k]=tmpB[j];
            j++;
        }
        else if(j>=tmpSize2){
            a[k]=tmpA[i];
            i++;
        }
        else if(tmpA[i]<tmpB[j]){
            a[k]=tmpA[i];
            i++;
        }
        else{
            a[k]=tmpB[j];
            j++;
        }
    }
}