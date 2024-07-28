#include<stdio.h>
#include<stdlib.h>//malloc関数を使うためのライブラリ
#include<string.h>//strcmp関数を使うためのライブラリ

struct Phone_book{
    char name[30];
    char num[30];
    struct Phone_book *left;
    struct Phone_book *right;
};


/*
mallocNode関数
addData関数
第一引数：名前
第二引数：電話番号
返却値：動的に確保したPhone_book構造体型領域のアドレス
*/
struct Phone_book *mallocNode(char namae[], char dennwabanngou[]){
    struct Phone_book *add;
    add = (struct Phone_book*)malloc(sizeof(struct Phone_book));

    if(add == NULL){
        return NULL;
    }

    strcpy((*add).name, namae);
    strcpy((*add).num, dennwabanngou);
    (*add).left = NULL;
    (*add).right = NULL;

    return add;
}


/*
addData関数
第一引数：rootノードのアドレス
第二引数：名前
第三引数；電話番号
返却値：rootノードのアドレス
*/
struct Phone_book* addData(struct Phone_book *root, char namae[], char dennwabanngou[]){
    struct Phone_book *node;
    if(root == NULL){
        root = mallocNode(namae, dennwabanngou);
        return root;
    }
    node = root;
    while(1){
        if( strcmp(namae, (*node).name) > 0){
            if( (*node).right == NULL ){
                (*node).right = mallocNode(namae, dennwabanngou);
                break;
            }
            node = (*node).right;
        }
        else if( strcmp(namae, (*node).name) < 0){
            if( (*node).left == NULL){
                (*node).left = mallocNode(namae, dennwabanngou);
                break;
            }
            node = (*node).left;
        }
        else{
            printf("%s already exit\n", namae);
            break;
        }
    }
    return root;
}


/*
searchData関数：二分探索木の中から指定した氏名の電話番号を画面に表示する関数
第一引数：rootノードのアドレス
第二引数：氏名
*/
    int searchData(struct Phone_book* root, char namae[]){
        struct Phone_book *node;
        node = root;

        while(1){
            if( strcmp(namae, (*node).name) > 0){
                if( (*node).right == NULL ){
                    printf("お探しの名前は存在しません\n");
                    return 0;
                }
                node = (*node).right;
            }
            else if( strcmp(namae, (*node).name) < 0){
                if( (*node).left == NULL){
                    printf("お探しの名前は存在しません\n");
                    return 0;
                }
                node = (*node).left;
            }
            else{
                printf("%sの電話番号は%sです\n",namae, (*node).num);
                return 0;
            }
        }
    }


    /*
    showallData関数：データを昇順に表示する関数(通りがけ順)
    第一引数：Phonebook構造体型のポインタ変数
    返り値：なし
    */
    void showallData(struct Phone_book* p){
    if( p == NULL){
        return ;
    }
    showallData ( (*p).left );
    printf("%s\n", (*p).name );
    showallData( (*p).right);
    }


/*
fcreateTree関数：ファイルから名前と電話番号を読み取り、二分探索木にノードとして追加する
第一引数：ファイル名
返り値：rootノードのアドレス
*/
struct Phone_book* fcreateTree(struct Phone_book *root){
    char filename[100];
    char nameFromFile[50];
    char numFromFile[50];
    FILE *fp;

    puts("Input filename");
    scanf("%s", filename);

    fp = fopen(filename,"r");
    if(fp == NULL){
        printf("ファイルのオープンに失敗しました\n");
        return root;
    }
    while(fscanf(fp,"%s%s",nameFromFile,numFromFile) != EOF) {
        root = addData(root, nameFromFile, numFromFile);
    }
    fclose(fp);

    return root;
}



    /*
    deleteNochildNode関数:
    第一引数：ｒｏｏｔノード
    第二引数：削除対象のノード
    第三引数：削除対象のノードの親ノード
    返り値：ｒｏｏｔノード
    */
    struct Phone_book *deleteNochildNode(struct Phone_book* root, struct Phone_book* node, struct Phone_book *parent){//リーフの削除。親ノードの左についているリーフなのか、親ノードの右についているリーフなのかで場合分けする
        if(parent != NULL){//削除対象のノードの親ノードが存在する場合
            if( (*parent).left == node ){//もし親ノードの左のポインタの値と、削除対象のノードの値が一致した場合、親ノードに対して、左の子を削除する
                (*parent).left = NULL;//削除対象のノードの親の左のポインタをヌルにする
            }
            else{//もし親ノードの右ポインタの値と、削除対象のノードの値が一致した場合、親ノードに対して、右の子を削除する
                (*parent).right = NULL;//削除対象のノードの親の右のポインタをヌルにする
            }
        free(node);//削除対象のノードのアドレスを開放する
        }
        else{//削除対象のノードの親ノードが無い場合、つまり二分探索木にｒｏｏｔしか無い状態でｒｏｏｔノードを消す場合
            free(node);
            root = NULL;
        }
        return root;
    }


/*
deleteOnechildNode関数
第一引数：ｒｏｏｔノード
第二引数：削除対象のノード
第三引数：削除対象のノードの子ノード
返り値：ｒｏｏｔノード
*/
    struct Phone_book *deleteOnechildNode(struct Phone_book *root, struct Phone_book *node, struct Phone_book *child){

        strcpy( (*node).name , (*child).name );//削除対象のノードの子の値(氏名)を、削除対象のノードにコピーすることで、削除対象のノードは削除されたこととなる
        strcpy( (*node).num , (*child).num );//削除対象のノードの子の値(電話番号)を、削除対象のノードにコピーすることで、削除対象のノードは削除されたこととなる
        (*node).left = (*child).left;//削除対象のノードの子の左のポインタの値を、削除対象のノードの左のポインタに代入することで、削除対象のノードは削除されたこととなる
        (*node).right = (*child).right;//削除対象のノードの子の右のポインタの値を、削除対象のノードの右のポインタに代入することで、削除対象のノードは削除されたこととなる
        free(child);//コピーしおわったら、コピー元は解法する
        return root;
    }


    /*
    deleteTwochildNode関数
    第一引数：ｒｏｏｔノード
    第二引数：削除対象のノード
    返り値：ｒｏｏｔノード
    */
    struct Phone_book *deleteTwochildNode(struct Phone_book *root, struct Phone_book *node){
        struct Phone_book *max;
        struct Phone_book *maxParent;
        max = (*node).left;
        maxParent = node;

        while((*max).right != NULL){//右がなくなるまで右に進み続ければ、それが、左側の最大のノード
            maxParent = max;
            max = (*max).right;
        }
        strcpy( (*node).name , (*max).name);//最大値の名前を削除対象のノードの名前にコピーすることで削除対象のノードは削除されたこととなる
        strcpy( (*node).num , (*max).num);
        if( (*max).left == NULL ){//右がなくなるまで進み続けたので右は当然ないのだが、左の子もまた、ない場合は、この最大値のコピー元は、子をもたないノードの削除方法として削除する
            root = deleteNochildNode(root, max, maxParent);//引数：root, 着目node, 親node
        }
        else{//右がなくなるまで進み続けたので右は当然ないのだが、左の子はある場合は、子を１つもつノードの削除方法として削除する
            root = deleteOnechildNode(root, maxParent, max);//引数：root, 着目node, 子node
        }
        return root;
    }


    /*
    removeData関数*
    第一引数：
    第二引数：
    返り値：
    */
    struct Phone_book *removeData(struct Phone_book *root, char namae[]){
        struct Phone_book *node;
        struct Phone_book *parent;
        node = root;
        parent = NULL;
        while(node != NULL){//削除対象のノードまで移動する
            if( (strcmp(namae, (*node).name)) < 0 ){//負のとき第一引数のほうが辞書的に先
                parent = node;
                node = (*node).left;//左に移動する
            }
            else if( (strcmp(namae, (*node).name)) > 0 ){//正のとき第一引数のほうが辞書的に後
                parent = node;
                node = (*node).right;//右に移動する
            }
            else{//対象ノードまで移動したらwhileループを抜ける
                break;
            }
        }
        //削除対象のノードが子を持たないか、１つもつか、２つもつかで場合分けする
        if( (*node).left == NULL && (*node).right == NULL ){//削除対象のノードが子を持たない場合
            root = deleteNochildNode(root, node, parent);
        }
        else if( ((*node).left != NULL && (*node).right == NULL) || ((*node).right != NULL && (*node).left == NULL) ){//削除対象のノードが右または左に子を持つ場合
            if( (*node).left != NULL) {//左に子を持つ場合
                    root = deleteOnechildNode( root,  node ,(*node).left);//引数：root, node, child
            }
            else{//右に子を持つ場合
                    root = deleteOnechildNode( root, node, (*node).right );//引数：root, node, child
            }
        }
        else{//削除対象のノードが右、左共に子を持つ場合
            root = deleteTwochildNode(root, node);
            }
    }



    /*main関数*/
    int main(void){
        struct Phone_book *root, *node;
        char dennwabanngou[30];
        char namae[30];
        root = NULL;

        int action;
        int loop = 1;
        int input;

    while(loop){
        printf("Input number that suggests action 1:add data from keyboard 2:add data from file 3:search data 4:show data 5:remove data 6:quit\n");
        scanf("%d", &action);
        switch(action){
            case 1:
                printf("電話番号");
                scanf("%s", dennwabanngou);
                printf("名前");
                scanf("%s", namae);
                root = addData(root, namae, dennwabanngou);
                break;

            case 2:
                root = fcreateTree(root);
                break;

            case 3:
                puts("探したい電話番号の氏名を入力してください");
                scanf("%s", namae);
                searchData(root, namae);
                break;

            case 4 :
                puts("show all data");
                showallData(root);
                printf("\n");
                break;

            case 5 :
                puts("Input name");
                scanf("%s", &namae);
                removeData(root, namae);
                break;

            case 6 :
                loop = 0;
                break;
        }
    }
}
