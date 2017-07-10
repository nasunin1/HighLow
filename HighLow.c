CHECKED#include <stdio.h>
#include <stdlib.h>

//未ドロー
#define NOCHECK 0
//既にドロー済みの場合
#define CHECKED 1
//山札の枚数
#define DECK 53

//カードドロー関数
int Draw(int[2],int[]);
//山札のリセット
void DECKReset(int[DECK]);

//メイン関数
int main (void)
{
  //山札の宣言
  int cardArray[DECK];
  //マークを格納する配列
  char marks[4][] =
  {
    "スペード",
    "ハート",
    "ダイヤ",
    "クローバー"
  };
  //プレイヤー持ち札
  int player[2];
  //ディラー持ち札
  int dealer[2];
  //山札のチェック初期化
  DECKReset(cardArray);
  //各プレイヤーはカードを1枚引く
  Draw(player);
  Draw(dealer);


  return 0;
}

//カードドロー関数
int Draw(int hand[2],cardArray[DECK])
{
  int flag = 0;
  //被らない番号を引くまでループ
  whie(flag == 0){
    //hand[マーク,番号]
    int random = rand() % 53 + 1;
    if(cardArray[random] == NOCHECK){
      cardArray[random] = CHECKED;
      flag = 1;
    }
  }
  //マークの格納
  hand[0] = random % 4;
  hand[1] = random / 13;
  return 0;
}

//デッキのチェックを初期化する関数
void DECKReset(int cardArray[DECK])
{
  //配列内をリセットする 配列のサイズ数分探索
  for(int i = 0;i < sizeof(cardArray); i ++)
  {
    cardArray[i] = NOCHECK;
  }
  return 0;
}
