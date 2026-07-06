#include"20260706_Header1_nishino.h"
#include"20260706_config1_nishino.h"
#include<iostream>
//回復
void Heal(int& hp)
{
	//HP回復
	hp += 20;
	//表示
	std::cout << "20回復しました。\n";
}
//入力チェック
int InputCheck(int min, int max)
{
	//変数宣言
	int num;
	//入力チェック
	while (true)
	{
		//数字の入力
		std::cin >> num;
		//入力が間違っているかどうかを確認します。
		if (min > num || max < num)
		{
			//間違っていたら再度入力を促す
			std::cout << "入力に誤りがあります。再度入力してください。\n";
		}
		else
		{
			//ループから抜ける
			break;
		}
	}
	//戻り値
	return num;
}

//実行関数
void Run()
{
	//変数宣言
	int playerHp = ConstNumber::PLEYER_HP;
	int select;
	//内容表示
	std::cout << "HPを回復させますか？\n1→回復\n2→現状のまま\n";
	//選択
	std::cout << "選択してください";
	//入力チェック関数に渡し、戻り値で選択肢を持ってくる
	select = InputCheck(ConstNumber::SELECT_MIN, ConstNumber::SELECT_MAX);
	//回復
	//1だったら回復
	if (select == 1)
	{
		Heal(playerHp);
	}
	else
	{
		std::cout << "回復しませんでした。\n";
	}
	//HP表示
	std::cout << "Playerのhpは、" << playerHp << "です\n";

}