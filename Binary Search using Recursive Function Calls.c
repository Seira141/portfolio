#include<stdio.h>
#include<stdlib.h>

/*ファイルからデータを読み込む*/ 
int *makeintarray(int n){
    int *ip = NULL;
    ip = (int*)malloc(sizeof(int) * n); 
    char filename[20];
    int i; 
    FILE *fp;
    printf("filename = "); 
    scanf("%s", filename); 
    fp = fopen(filename, "r"); 
    if(fp == NULL) {
        printf("ファイルを開くことが出来ませんでした．\n"); 
        return ;
    }

    for(i = 0; i< n ; i++){ 
        fscanf(fp, "%d", &(ip[i]) );
    }
    fclose(fp); 
    return ip;
    }
/*選択ソート*/
int *sort(int a[], int n){
    int i, k, j;
    for(i = 0 ; i < n - 1 ; i++){ 
    j = i ;
    for(k = i + 1 ; k < n ; k++){ 
        if(a[j] > a[k]){j = k;}
    }
    int tmp; 
    tmp = a[j]; 
    a[j] = a[i]; 
    a[i] = tmp;
    } 
}

/*二分探索*/
int nibunn(int a[], int x, int lowid, int highid){ 
    int midid;
    midid = (lowid + highid)/2; 
    if(a[midid] == x){
    return midid; 
    }
    else if (lowid > highid) { 
        printf("見つかりませんでした"); 
        exit(1);
    }
    else if(a[midid] < x){
        return nibunn(a, x, midid + 1, highid); // 右半分に絞り込む 
    }//midid + 1 =lowid
    else{
        return nibunn(a, x, lowid ,midid - 1);//左半分に絞り込む 
    }//midid - 1 = highid
        return midid; 
    }
    /*配列の出力*/
    int print_array(int a[], int n){ 
    int i;
    for(i = 0 ; i < n ; i++){ 
        printf("%d ",a[i]);
    }
    printf("\n"); 
    }
    /*main 関数*/ 
    int main(void){
        int n;
        puts("データの個数は何個ですか。"); 
        scanf("%d",&n);
        int *array = NULL; 
        array = makeintarray(n); 
        puts("以下の配列を二分探索します。"); 
        print_array(array, n);
        sort(array, n);
        puts("並べ替えました"); 
        print_array(array, n);
        printf("探したい値を入力してください\n"); 
        int target;
        scanf("%d",&target);
        printf("%d を探します\n",target);

        int lowid, highid;
        int midid;
        lowid = 0; 
        highid = n;
        midid = nibunn(array, target, lowid, highid); 
        printf("%d は%d 番目にみつかりました\n",target ,midid);
    }
