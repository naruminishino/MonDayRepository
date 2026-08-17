#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int board[9] = { 0 };
    int dice1;
    int dice2;
    int choice;
    int player = 1;
    int count = 0;
    int i;
    // 乱数の初期化
    srand((unsigned int)time(NULL));
    cout << "==============================" << endl;
    cout << "        ジャックポット        " << endl;
    cout << "==============================" << endl;
    // ゲームが終わるまで繰り返す
    while (true)
    {
        cout << endl;
        cout << "PLAYER " << player << " のターン" << endl;
        // サイコロを2個振る
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        cout << "サイコロ1：" << dice1 << endl;
        cout << "サイコロ2：" << dice2 << endl;
        // 選べるマスを表示
        cout << "取れるマス：";
        if (board[dice1 - 1] == 0)
        {
            cout << dice1 << " ";
        }
        if (board[dice2 - 1] == 0 && dice2 != dice1)
        {
            cout << dice2 << " ";
        }
        if (board[dice1 + dice2 - 1] == 0)
        {
            cout << dice1 + dice2 << " ";
        }
        cout << endl;
        // 取れるマスがあるか確認
        bool canTake = false;
        if (dice1 + dice2 <= 9)
        {
            if (board[dice1 - 1] == 0 ||
                board[dice2 - 1] == 0 ||
                board[dice1 + dice2 - 1] == 0)
            {
                canTake = true;
            }
        }
        // サイコロの目が9以下の場合のチェック
        if (dice1 <= 9 && board[dice1 - 1] == 0)
        {
            canTake = true;
        }
        if (dice2 <= 9 && board[dice2 - 1] == 0)
        {
            canTake = true;
        }
        // 取れるマスがない場合
        if (!canTake)
        {
            cout << "取れるマスがありません。" << endl;
            cout << "PLAYER " << player << " の負けです。" << endl;
            break;
        }
        // プレイヤーが取るマスを選択
        while (true)
        {
            cout << "取るマスを入力してください：" << endl;
            cin >> choice;
            // 1～9以外は入力できない
            if (choice < 1 || choice > 9)
            {
                cout << "1～9を入力してください。" << endl;
            }
            // マスがすでに取られている
            else if (board[choice - 1] != 0)
            {
                cout << "そのマスはすでに取られています。" << endl;
            }
            // サイコロの目または合計ではない
            else if (choice != dice1 &&
                choice != dice2 &&
                choice != dice1 + dice2)
            {
                cout << "サイコロの目、または合計のマスを選んでください。" << endl;
            }
            else
            {
                break;
            }
        }
        // 選択したマスをプレイヤーのものにする
        board[choice - 1] = player;
        // 取ったマスの数を増やす
        count++;
        cout << "PLAYER " << player << " が " << choice
            << " のマスを取りました！" << endl;
        // 現在のマスを表示
        cout << endl;
        cout << "現在のマス：" << endl;
        for (i = 0; i < 9; i++)
        {
            if (board[i] == 0)
            {
                cout << i + 1 << " ";
            }
            else
            {
                cout << "○ ";
            }
        }
        cout << endl;
        // すべてのマスが取られた場合
        if (count == 9)
        {
            cout << endl;
            cout << "すべてのマスが取られました！" << endl;
            cout << "PLAYER " << player << " の勝利です！" << endl;
            break;
        }
        // プレイヤーを交代
        if (player == 1)
        {
            player = 2;
        }
        else
        {
            player = 1;
        }
    }
    return 0;
}