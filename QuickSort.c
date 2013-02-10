//
//  QuickSort.c
//  MergeSort
//
//  Created by Haewon Kwak on 13-02-10.
//  Copyright (c) 2013 Haewon Kwak. All rights reserved.
//

#include <stdio.h>

void quickSort(int a[], int l, int n);
int partition(int a[], int l, int r);
void median(int a[], int left, int right);
void swap(int *dex1, int *dex2);

void quickSort(int a[], int l, int n){
    if(l<n){
//        swap(&a[l],&a[n]);
//        median(a, l, n);
        int par=partition(a, l, n);
        quickSort(a, l, par-1);
        quickSort(a, par+1, n);
    }
}

int partition(int a[], int l, int r){
    int p=a[l];
    int i=l+1;
    for(int j=l+1;j<=r;j++){
        if(a[j]<p){
            swap(&a[j], &a[i]);
            i+=1;
        }
    }
    swap(&a[l], &a[i-1]);
    return i-1;
}

void median(int a[], int left, int right){
    int mid = (left + right) / 2;
    if ((a[mid] > a[left]&&a[mid]<a[right])||(a[mid] > a[right]&&a[mid]<a[left])){
        swap(&a[left],&a[mid]);
    }
    else if ((a[right] > a[mid]&&a[right]<a[left])||(a[right] < a[mid]&&a[right]>a[left])){
        swap(&a[left],&a[right]);
    }
}

void swap(int *dex1, int *dex2) {
    int temp = *dex1;
    *dex1 = *dex2;
    *dex2 = temp;
}