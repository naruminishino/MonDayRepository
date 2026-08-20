#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    //ローカル変数
    int player;
    int cpu;
    int result;
    int i;
    int win = 0;
    int lose = 0;
    int draw = 0;
    //乱数の初期化
    srand((unsigned int)time(nullptr));
    //画面上に文字を表示
    cout << "じゃんけんゲームを開始します。" << endl;
    //ゲームを５回開始する
    for (i = 0; i < 5; i++)
    {
        cout << endl;
        cout << "-------- " << i + 1 << "回戦 --------" << endl;
        //正しい文字が入力するまで繰り返す
        while (true)
        {
            cout << "0：グー　1：チョキ　2：パー" << endl;
            cout << "プレイヤーの手を入力してください：" << endl;
            cin >> player;
            //０～２が入力されたらループを抜ける
            if (player >= 0 && player <= 2)
            {
                break;
            }
            //０～２以外が入力された場合再入力を促す
            cout << "入力に誤りがあります。再入力してください。" << endl;
        }
        //cpuの手を０～２の中でランダムに設定する
        cpu = rand() % 3;
        //プレイヤーが選んだ数字に応じて手を表示する
        switch (player)
        {
        case 0:
            cout << "PLAYER：グー" << endl;
            break;
        case 1:
            cout << "PLAYER：チョキ" << endl;
            break;
        case 2:
            cout << "PLAYER：パー" << endl;
            break;
        }
        //cpuが選んだ数字に応じて手を表示する
        switch (cpu)
        {
        case 0:
            cout << "CPU：グー" << endl;
            break;
        case 1:
            cout << "CPU：チョキ" << endl;
            break;
        case 2:
            cout << "CPU：パー" << endl;
            break;
        }
        //プレイヤーとcpuが選んだ数字を比較する
        result = player - cpu;
        //プレイヤーが勝つ場合
        if (result == -1 || result == 2)
        {
            cout << "PLAYER WIN!" << endl;
            //プレイヤーの勝利数を１増やす
            win++;
        }
        //プレイヤーとcpuの数字が同じ場合
        else if (result == 0)
        {
            cout << "DRAW" << endl;
            //引き分けの回数を１増やす
            draw++;
        }
        else
        {
            cout << "CPU WIN!" << endl;
            //プレイヤーの敗北数を１増やす
            lose++;
        }
    }

    //５回戦が終わったので結果を表示する
    cout << endl;
    cout << "==============================" << endl;
    cout << "5回勝負終了！" << endl;
    //勝ち・引き分け・負けを表示する
    cout << win << "勝 "
        << draw << "分 "
        << lose << "敗" << endl;
    cout << "==============================" << endl;
    return 0;
}
