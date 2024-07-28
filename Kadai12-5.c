#include<math.h>
#include<stdio.h>
#define sqr(n) ((n)*(n))

//点の座標を表す構造体
typedef struct {
    double x;
    double y;
}Point;

//自動車を表す構造体
typedef struct{
    Point pt;
    double fuel;
}Car;

//点paと点pbの距離を返す
//入力値：２点の座標
//返却値：２点間の距離
double distance_of(Point pa, Point pb){
    return sqrt(sqr(pa.x - pb.x) + sqr(pa.y - pb.y));
}

//自動車の現在位置と残り燃料を表示
//引数：自動車の現在位置と、自動車の燃料の構造体
void put_info(Car c){
    printf("現在位置：(%.2f, %.2f)\n", c.pt.x, c.pt.y);//(c.pt.x)Ｃ構造体の、座標メンバーの、ｘ座メンバ
    printf("残り燃料：%.2fリットル\n", c.fuel);
}

//cの指す車を目的座標destに移動する
//引数：Car構造体のアドレス、目的地の座標（車の座標と、車の燃料は更新したいので、アドレスを渡してやる）
int move (Car *c, Point dest){
    double d = distance_of(c->pt, dest);//車の座標と、目的地の座標の２点間の距離を計算する
    if(d > c->fuel)//もし２点間の距離が、車の燃料より大きかったら、移動できないので、 main関数に戻る
        return 0;//移動不可
    c->pt = dest;//目的地の座標を、車の現在位置の座標に代入する（目的地に到着した）
    c->fuel -= d;//車の燃料から、移動距離を引く
    return 1;
}

int main (void){
    Car mycar = {{0.0, 0.0}, 90.0};
    while(1){
        int select;//移動するかしないかの変数
        Point dest;//目的地の座標
        put_info(mycar);//車の現在位置と、燃料を出力する
        printf("移動しますか【yes...1/No...0】:");
        scanf("%d", &select);
        if(select != 1)break;//0か1以外だったら、移動しない。whileループを抜ける
        int docchi;
        printf("目的地の座標を入力【1】,x方向とy方向の移動距離を入力【2】");
        scanf("%d", &docchi);
        if(docchi == 1){
            printf("目的地のＸ座標"); scanf("%lf", &dest.x);//1だったら、目的地のｘ座標を入力して、
            printf("　　　　Ｙ座標"); scanf("%lf", &dest.y);//目的地のｙ座標も入力する
            if(!move(&mycar, dest))
            puts("\a燃料不足で移動できません。");
        }
        else if(docchi == 2){//距離が入力されたときは、現在地に移動距離を足したものが目標値の座標
            printf("X方向の移動距離："); scanf("%lf", &dest.x);
            printf("Y方向の移動距離："); scanf("%lf", &dest.y);
            dest.x += mycar.pt.x;
            dest.y += mycar.pt.y;
            if(!move(&mycar, dest))
            puts("\a燃料不足で移動できません。");
        }
    }
    return 0;
}
