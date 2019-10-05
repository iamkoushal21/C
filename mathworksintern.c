#include<stdio.h>

int allsame(int number, int arr[10]) {
	int check = 0 ,i =0,  num = arr[0];
	while(arr[i] == num) {
		i++;
	}

	if (i == number) {
		check = 1;
	} 

	return check;
}

int  main() {
	int arr[10], i=0, num=0, max=0, pos=0,temp=0, count =0, check=0;
	printf("Enter total numbers   ");
	scanf("%d", &num);
	printf("Enter number\n");
	for(i=0;i<num;i++) {
		printf("Enter %d element :  ", i+1);
		scanf("%d", &arr[i]);
	}
	check = allsame(num, arr);
	while(check != 1) {
		max = arr[0];
		pos = 0;
		for(i=1;i<num;i++) {
			if (max < arr[i]) {
				pos = i;
				max = arr[i];
			}

		}
		temp = arr[pos];
		arr[pos] = arr[num-1];
		arr[num-1] = temp;
		for(i=0;i<num-1;i++) {
			arr[i]++;
		}
		count++;
		check = allsame(num, arr);
	}	

	printf("\n----------%d", count);
	return 0;
}

