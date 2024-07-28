
//ライブラリの導入とマクロ定義
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define YAMAFUDA_NUM 260
#define DECK_NUM 52

//カードのマークと数を表す構造体の宣言
typedef struct markAndHand{
    char mark[20];
    int Hand;
}markAndHands;

//山札表す構造体型の配列
markAndHands yamafuda[YAMAFUDA_NUM] = { {"　　ハート", 1},{"　スペード", 1},{"　　ダイア", 1},{"クローバー", 1}, {"　　ハート", 2},{"　スペード", 2},{"　　ダイア", 2},{"クローバー",2 } ,{"　　ハート",3 },{"　スペード", 3},{"　　ダイア",3},{"クローバー", 3}, {"　　ハート",4 },{"　スペード", 4},{"　　ダイア", 4},{"クローバー", 4} ,{"　　ハート", 5},{"　スペード", 5},{"　　ダイア", 5},{"クローバー", 5} ,{"　　ハート", 6},{"　スペード", 6},{"　　ダイア", 6},{"クローバー", 6} ,{"　　ハート", 7},{"　スペード", 7},{"　　ダイア", 7},{"クローバー", 7}, {"　　ハート", 8},{"　スペード", 8},{"　　ダイア", 8},{"クローバー", 8} ,{"　　ハート", 9},{"　スペード", 9},{"　　ダイア", 9},{"クローバー", 9}, {"　　ハート", 10},{"　スペード", 10},{"　　ダイア", 10},{"クローバー", 10}, {"　　ハート", 11},{"　スペード", 11},{"　　ダイア", 11},{"クローバー", 11}, {"　　ハート",12 },{"　スペード", 12},{"　　ダイア", 12},{"クローバー", 12},  {"　　ハート", 13},{"　スペード", 13},{"　　ダイア", 13},{"クローバー", 13}, {"　　ハート", 1},{"　スペード", 1},{"　　ダイア", 1},{"クローバー", 1}, {"　　ハート", 2},{"　スペード", 2},{"　　ダイア", 2},{"クローバー",2 } ,{"　　ハート",3 },{"　スペード", 3},{"　　ダイア",3},{"クローバー", 3}, {"　　ハート",4 },{"　スペード", 4},{"　　ダイア", 4},{"クローバー", 4} ,{"　　ハート", 5},{"　スペード", 5},{"　　ダイア", 5},{"クローバー", 5} ,{"　　ハート", 6},{"　スペード", 6},{"　　ダイア", 6},{"クローバー", 6} ,{"　　ハート", 7},{"　スペード", 7},{"　　ダイア", 7},{"クローバー", 7}, {"　　ハート", 8},{"　スペード", 8},{"　　ダイア", 8},{"クローバー", 8} ,{"　　ハート", 9},{"　スペード", 9},{"　　ダイア", 9},{"クローバー", 9}, {"　　ハート", 10},{"　スペード", 10},{"　　ダイア", 10},{"クローバー", 10}, {"　　ハート", 11},{"　スペード", 11},{"　　ダイア", 11},{"クローバー", 11}, {"　　ハート",12 },{"　スペード", 12},{"　　ダイア", 12},{"クローバー", 12},  {"　　ハート", 13},{"　スペード", 13},{"　　ダイア", 13},{"クローバー", 13}, {"　　ハート", 1},{"　スペード", 1},{"　　ダイア", 1},{"クローバー", 1}, {"　　ハート", 2},{"　スペード", 2},{"　　ダイア", 2},{"クローバー",2 } ,{"　　ハート",3 },{"　スペード", 3},{"　　ダイア",3},{"クローバー", 3}, {"　　ハート",4 },{"　スペード", 4},{"　　ダイア", 4},{"クローバー", 4} ,{"　　ハート", 5},{"　スペード", 5},{"　　ダイア", 5},{"クローバー", 5} ,{"　　ハート", 6},{"　スペード", 6},{"　　ダイア", 6},{"クローバー", 6} ,{"　　ハート", 7},{"　スペード", 7},{"　　ダイア", 7},{"クローバー", 7}, {"　　ハート", 8},{"　スペード", 8},{"　　ダイア", 8},{"クローバー", 8} ,{"　　ハート", 9},{"　スペード", 9},{"　　ダイア", 9},{"クローバー", 9}, {"　　ハート", 10},{"　スペード", 10},{"　　ダイア", 10},{"クローバー", 10}, {"　　ハート", 11},{"　スペード", 11},{"　　ダイア", 11},{"クローバー", 11}, {"　　ハート",12 },{"　スペード", 12},{"　　ダイア", 12},{"クローバー", 12},  {"　　ハート", 13},{"　スペード", 13},{"　　ダイア", 13},{"クローバー", 13}, {"　　ハート", 1},{"　スペード", 1},{"　　ダイア", 1},{"クローバー", 1}, {"　　ハート", 2},{"　スペード", 2},{"　　ダイア", 2},{"クローバー",2 } ,{"　　ハート",3 },{"　スペード", 3},{"　　ダイア",3},{"クローバー", 3}, {"　　ハート",4 },{"　スペード", 4},{"　　ダイア", 4},{"クローバー", 4} ,{"　　ハート", 5},{"　スペード", 5},{"　　ダイア", 5},{"クローバー", 5} ,{"　　ハート", 6},{"　スペード", 6},{"　　ダイア", 6},{"クローバー", 6} ,{"　　ハート", 7},{"　スペード", 7},{"　　ダイア", 7},{"クローバー", 7}, {"　　ハート", 8},{"　スペード", 8},{"　　ダイア", 8},{"クローバー", 8} ,{"　　ハート", 9},{"　スペード", 9},{"　　ダイア", 9},{"クローバー", 9}, {"　　ハート", 10},{"　スペード", 10},{"　　ダイア", 10},{"クローバー", 10}, {"　　ハート", 11},{"　スペード", 11},{"　　ダイア", 11},{"クローバー", 11}, {"　　ハート",12 },{"　スペード", 12},{"　　ダイア", 12},{"クローバー", 12},  {"　　ハート", 13},{"　スペード", 13},{"　　ダイア", 13},{"クローバー", 13}, {"　　ハート", 1},{"　スペード", 1},{"　　ダイア", 1},{"クローバー", 1}, {"　　ハート", 2},{"　スペード", 2},{"　　ダイア", 2},{"クローバー",2 } ,{"　　ハート",3 },{"　スペード", 3},{"　　ダイア",3},{"クローバー", 3}, {"　　ハート",4 },{"　スペード", 4},{"　　ダイア", 4},{"クローバー", 4} ,{"　　ハート", 5},{"　スペード", 5},{"　　ダイア", 5},{"クローバー", 5} ,{"　　ハート", 6},{"　スペード", 6},{"　　ダイア", 6},{"クローバー", 6} ,{"　　ハート", 7},{"　スペード", 7},{"　　ダイア", 7},{"クローバー", 7}, {"　　ハート", 8},{"　スペード", 8},{"　　ダイア", 8},{"クローバー", 8} ,{"　　ハート", 9},{"　スペード", 9},{"　　ダイア", 9},{"クローバー", 9}, {"　　ハート", 10},{"　スペード", 10},{"　　ダイア", 10},{"クローバー", 10}, {"　　ハート", 11},{"　スペード", 11},{"　　ダイア", 11},{"クローバー", 11}, {"　　ハート",12 },{"　スペード", 12},{"　　ダイア", 12},{"クローバー", 12},  {"　　ハート", 13},{"　スペード", 13},{"　　ダイア", 13},{"クローバー", 13} };

//手札を表す構造体型の配列
markAndHands card[100] = {};

int cardNum; //手札の配列の要素数を数える変数

int count0 = 0;//山札から１つカードが引かれるたびにカウントアップする変数　＝　山札から引かれたカードの枚数を数える


// 引数：なし
// 返り値:なし
// 動作:実行すると配列に５デッキ分のカードを代入する　＝　山札をリセットする
void resetYamafuda(void){

    puts("山札をリセットします");
    sleep(2);
    int i, j, l;
    int k = 1;
    for(l = 0 ; l < 5 ; l++){//山札をデッキ(52枚)ごとに捉える
        for(j = l*DECK_NUM ; j < (l+1)*DECK_NUM ; j += 4 ){//山札を4枚(同じ数字が連続する区間)ごとに捉える
            for(i = j ; i < j+4 ; i++){//山札を1枚ごとに捉える
                yamafuda[i].Hand = k;
            }
            k++;
        }
        k = 1;
    }

}


// 引数：なし
// 返り値：1から260のランダムな整数１つ
// 動作：実行すると1から260の整数をランダムに生成する　＝　カードを一枚配る
// 整数１が生成されたからといって、その後１が生成される確率は減らない
int dealCard(void){

    int card = rand();//randだけ呼び出す
    card = (card % YAMAFUDA_NUM) + 1;
    return card;//1から259までのランダムな整数を返す

}

// 引数:なし
// 返り値:なし
// 動作:実行すると、yamafuda配列の要素を出力する　＝　山札のカードを見せる
void printYanafuda(void){

    int i, j;
    printf("＜yamafuda＞\n");
    for( j = 0 ; j < YAMAFUDA_NUM ; j += 12){
        for(i = j ; i < j + 12 ; i++){
            printf("%s:%d  " , yamafuda[i].mark, yamafuda[i].Hand);
        }
        printf("\n");//12個表示するたびに改行を入れる
    }

}

// 引数：cardNum ...手札のカードの枚数
// 引数：card[] ... 手札のカードを記憶している引数
// 返り値：なし
// 動作：実行すると、手札のカードを画面上に表示する
// 1, 11, 12, 13 はそれぞれA, J, Q, K と表示する
void showCards(int cardNum, markAndHands card[]){

    int i;
    printf("Hand：");
    for(i = 0 ; i < cardNum ; i++){
        if(card[i].Hand == 1){//1のとき、Aと表示する
            printf("[%s:A] ", card[i].mark);
        }
        else if(card[i].Hand == 11){//11のとき、Jと表示する
            printf("[%s:J] ", card[i].mark);
        }
        else if(card[i].Hand == 12){//12のとき、Qと表示する
            printf("[%s:Q] ", card[i].mark);
        }
        else if(card[i].Hand == 13){//13のとき、Kと表示する
            printf("[%s:K] ", card[i].mark);
        }
        else{//1, 11, 12, 13以外のとき、Handメンバの値がカードの値
            printf("[%s:%d] ",card[i].mark , card[i].Hand);
        }
    }
    printf("\n");

}


// 引数：cardNum ...手札のカードの枚数
// 引数：card[] ... 手札のカードを記憶している引数
// 返り値：手札のカードから計算された点数（整数）
// 動作：実行すると、手札のカードを計算し、合計点数を返す
// 11, 12, 13は10として計算する
// Aは1または11として計算する
int calcScore(int cardNum, markAndHands card[]){

    int totalScore = 0;
    int countA = 0;
    int i;

    for(i = 0 ; i < cardNum ; i++){
        if(card[i].Hand != 1 && card[i].Hand != 11 && card[i].Hand != 12 && card[i].Hand != 13){
            totalScore += card[i].Hand;
        }
        else if( card[i].Hand == 11 || card[i].Hand == 12 || card[i].Hand == 13){//11, 12, 13は10として加算する
            totalScore += 10;
        }
        else if( card[i].Hand == 1){
            totalScore += 11;
            countA++;
        }
        while(totalScore > 21 && countA >= 1){
                totalScore -= 10;
                countA -= 1;
        }
    }
    return totalScore;

}


//引数：なし
//返り値：プレイヤーの点数
//動作：実行すると、プレイヤーのゲームターンを実行する。ターンが終了すると、プレイヤーの得点を返す。
int playerTurn(void){

    cardNum = 0;//手札の配列の要素数を０に初期化
    printf("========PLAYER TURN========\n");

    int i;
    for(i = 2 ; i > 0 ; i--){//最初にカードが2枚配られる
            int hiitakazu;
            int rannsuu;
            point2:
            rannsuu = dealCard();
            hiitakazu = yamafuda[rannsuu].Hand;//山札配列のrannsuu番目のHandメンバの値がhiitakazu
            if (hiitakazu != 0){
                card[cardNum].Hand = hiitakazu;
                strcpy(card[cardNum].mark , yamafuda[rannsuu].mark);
                cardNum++;
                yamafuda[rannsuu].Hand = 0;//カードを引いたら、カードがないことを表す０を代入する
                count0 += 1;//
                if(count0 >= 3){
                    resetYamafuda();
                    count0 = 0;
                }
            }
            else if(hiitakazu == 0){
                goto point2;
            }
    }


    while(1){
        printYanafuda();//山札を表示する（本当のゲームでは山札のカードは見えないが、確認のため表示させている）
        showCards(cardNum, card);//手札のカードを表示する
        printf("Select (Hit -> 1, Stand -> 2): ");
        int Select;
        scanf("%d", &Select);
        printf("%d\n", Select);
        if(Select == 1){//ヒットが選択された場合
            int hiitakazu;//引いたカードの数値を格納する変数
            int rannsuu;//dealCard関数の返り値である１から259までのランダムな整数を格納する変数
            point1:
            rannsuu = dealCard();
            hiitakazu = yamafuda[rannsuu].Hand;//山札配列のrannsuu番目のHandメンバの値がhiitakazu
            if (hiitakazu != 0){
                card[cardNum].Hand = hiitakazu;//引いたカードの数字を手札の配列に格納する
                strcpy(card[cardNum].mark , yamafuda[rannsuu].mark);//引いたカードのマ－クを手札の配列に格納する
                cardNum++;//現在の手札のカードの枚数をインクリメント
                yamafuda[rannsuu].Hand = 0;//カードを引いたら、カードがないことを表す０を代入する
                count0 += 1;//山札から引いたカードの枚数をカウントアップする
                if(count0 >= 3){//山札の枚数の半分以上カードが引かれた場合
                    resetYamafuda();//山札をリセットする
                    count0 = 0;//山札から引いたカードの枚数は再び０枚となる
                }
            }
            else if(hiitakazu == 0){//カードがないことを表す０を引いてしまった場合
                goto point1;//カードを引き直す
            }
        }

        else if(Select == 2){//standが選択された場合
            return calcScore(cardNum, card);//手札の合計点を計算し、playerturnを終える
        }
    }

}


//引数：なし
//返り値：ディーラーの点数
//動作：実行すると、ディーラーのゲームターンを実行する。ターンが終了すると、ディーラーの得点を返す。
int dealerTurn(void){

    cardNum = 0;
    printf("========DEALER TURN========\n");

    int i;
    for(i = 2 ; i > 0 ; i--){//最初にカードが2枚配られる
            int hiitakazu;
            int rannsuu;
            point3:
            rannsuu = dealCard();
            hiitakazu = yamafuda[rannsuu].Hand;//山札配列のrannsuu番目のHandメンバの値がhiitakazu
            if (hiitakazu != 0){
                card[cardNum].Hand = hiitakazu;
                strcpy(card[cardNum].mark , yamafuda[rannsuu].mark);
                cardNum++;
                yamafuda[rannsuu].Hand = 0;//カードを引いたら、カードがないことを表す０を代入する
                count0 += 1;//
                if(count0 >= 3){
                    resetYamafuda();
                    count0 = 0;
                }
            }
            else if(hiitakazu == 0){
                goto point3;
            }
    }


    while(1){
        printYanafuda();
        showCards(cardNum, card);
        printf("Select (Hit -> 1, Stand -> 2): ");
        int Select;
        if(calcScore(cardNum, card) < 17){
            Select = 1;
        }
        else if(calcScore(cardNum, card) >= 17){
            Select = 2;
        }
        printf("---DEALER THINKING---");
        sleep(2);
        printf("%d\n", Select);
        if(Select == 1){
            int hiitakazu;
            int rannsuu;
            point2:
            rannsuu = dealCard();
            hiitakazu = yamafuda[rannsuu].Hand;
            if (hiitakazu != 0){
                card[cardNum].Hand = hiitakazu;
                strcpy(card[cardNum].mark , yamafuda[rannsuu].mark);
                cardNum++;
                yamafuda[rannsuu].Hand = 0;
                count0 += 1;
                if(count0 >= 3){
                    resetYamafuda();
                    count0 = 0;
                }
            }
            else if(hiitakazu == 0){
                goto point2;
            }
        }
        else if(Select == 2){
            return calcScore(cardNum, card);
        }
    }

}

// 引数： pScore ... プレイヤーの点数
// 引数： dScore ... ディーラーの点数
// 返り値：　プレイヤーの勝利 -> 1, プレイヤーの敗北 -> -1
// 動作：　プレイヤーとディーラーの点数を比較し、勝敗を判定、判定結果を画面に表示する
int getResult(int pScore, int dScore){

    printf("P: %d vs D: %d\n", pScore, dScore);
    if(pScore >= 22){//プレイヤーがバーストしたらプレイヤーの負け
        printf("Player Loose...");
        return -1;
    }
    else if(dScore >= 22){//ディーラーがバーストしたら、プレイヤーの勝ち
        printf("Player Win!");
        return 1;
    }
    else if(pScore > dScore){//プレイヤーのスコアの方がおおきければプレイヤーの勝ち
        printf("Player Win!");
        return 1;
    }
    else{//それ以外ならプレイヤーの負け
        printf("Player Loose...");
        return -1;
    }

}


// 引数：なし
// 返り値：プレイヤーが勝利->1, プレイヤーが敗北->-1
// プレイヤーとディーラーの１対１のBJのゲームを実行する。
int playGame(void){

    int pScore = playerTurn();

    int dScore = dealerTurn();

    int result = getResult(pScore, dScore);

    return result;

}

// 引数:なし
// 返り値：なし
// １ゲームごとに掛け金をかけ、ゲームを実行する。持ち金がなくなるか、ゲームをやめるまで、ゲームは繰り返される
int main(void){
    srand((unsigned) time(NULL)); // 乱数生成のシード初期化(1回だけやる)
    printf("==================GAME START==================\n");
    int result;
    int loop = 1;
    int money = 100;
    int bet;
    while(loop && money > 0){
        printf("いくらベットしますか？ 持ち金：%d\n", money);
        scanf("%d", &bet);
        money -= bet;

        result = playGame();

        if(result == 1){
            money = money + bet * 2;
            printf("持ち金：%d\n", money);
        }
        else{
            printf("持ち金：%d\n", money);
        }


        if(money <= 0){
            printf("持ち金がなくなりました。ゲーム終了。\n");
            loop = 0;
        }
        else{
            printf("continue? Yes -> 1 No -> 0\n");
            scanf("%d", &loop);
        }
    }
printf("==================GAME END==================\n");
}
