#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // 乱数の初期化
    int answer = -1;      
    int question;         
    int count = 0;        
    
    srand((unsigned int)time(nullptr));
    // 0から100の中からランダムに数字を一つ決める
    question = rand() % 101;
    // 画面に文字を表示する
    cout << "数字当てゲーム" << endl;
    cout << "0～100までの数字を当ててください。" << endl;
    //正解するまで繰り返し
    while (question != answer)
    {
        count++;

        while (true)
        {
            // プレイヤーに数字を入力させる
            cout << "0～100の数字を入力してください：" << endl;
            cin >> answer;
            // 0未満または100より大きい数字が入力された場合
            if (answer < 0 || answer > 100)
            {//　入力に誤りがあることを表示
                cout << "入力に誤りがあります。再入力してください。" << endl;
            }
            else
            {
                break;
            }
        }
       // 入力された数字が正解より大きい場合
        if (question > answer)
        { 
            cout << "もっと大きい数字です。" << endl;
        }
        else if (question < answer)
        {
            cout << "もっと小さい数字です。" << endl;
        }
    }
    //　正解した場合の処理
    cout << endl;
    cout << "おめでとうございます！正解です！" << endl;
    // 正解した数字を表示
    cout << "正解：" << answer << endl;
    //　正解するまでにかかった回数を表示
    cout << count << "回目で当てることができました。" << endl;

    return 0;
}