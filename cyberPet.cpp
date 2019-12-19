#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

//游戏菜单打印//
void printHead();
void printMainMenu();
void printLongStar();
void printShortStar();
void printDividerStar();
void printIncident();
void printRaise();

//逻辑排序//
//行动菜单逻辑//
void switchMoveMenu(char);
//工作菜单逻辑//
void switchWorkMenu(char);
//购买事物逻辑//
void switchBuyFood(char);
//宠物类别认养类型排序
void switchChoosePet(char);
//系统功能逻辑排序//
void switchSystemFun(char);
//喂食逻辑//
void switchFeedFun(char);
//宠物性别逻辑
void switchSexyChoose(char);

//player class
class Player {
	friend class Food;
	friend class Pet;
	friend class System;
private:
	//体力
	int phy;
	//金钱
	int money;
	//行动
	int movePoint;
	//粗糙粮食数量
	int rawFoodNum;
	//精致粮食数量
	int goodFoodNum;
	//火腿数量
	int HuoTuiNum;
public:
	//初始化参数
	Player() {
		phy = 100;
		money = 100;
		movePoint = 7;
		HuoTuiNum = 0;
		rawFoodNum = 0;
		goodFoodNum = 0;
	}
	void workHomeTea();//家教
	void workMc();//金拱门兼职
	void workMow();//割草

	void buyRawFood();//购买粗糙宠物粮食
	void buyGoodFood();//购买粗糙食物
	void buyHuoTui();//买火腿

	//使用食物函数
	void useRaw();
	void useHuo();
	void useGood();
	//获取食物数量
	int showRaw() {
		return rawFoodNum;
	}
	int showGood() {
		return goodFoodNum;
	}
	int showHuo() {
		return HuoTuiNum;
	}

	void playerRest();//休息
	void playerSleep();//睡觉
	void cleanPlayer();//清洁
	void playPlayer();//玩耍

	int showPhy() {
		return phy;
	};//体力显示
	int showMovePoint() {
		return movePoint;
	};//行动力显示
	int showMoney() {
		return money;
	};//金钱显示

	//重置
	void reset() {
		phy = 100;
		money = 100;
		movePoint = 0;
		HuoTuiNum = 0;
		rawFoodNum = 0;
		goodFoodNum = 0;
	}
};
//独立控制函数
void work();//工作
void buy();//买东西
void rest();//休息
void sleep();//睡觉

//外部控制函数
//玩家与宠物
void use();//使用物品
void play();//玩耍
void clean();//清洁
//外部对象
 Player player;

//宠物基类
class Pet {
	friend class Player;
	friend class System;
protected:
	//品种
	//猫1 狗2
	int vary;
	int sex;
	string* name;
	//饱食度
	int feedDegree;
	//愉悦度
	int moodDegree;
	int weight;
	//清洁度
	int cleanDegree;
public:
	int lastDay;
	int cleanDay;
	int cleanTime;
	//数值返回
	virtual int getVary()=0;
	virtual int getSex()=0;
	virtual string getName()=0;
	virtual int getMoodDegree()=0;
	virtual int getWeight()=0;
	virtual int getCleanDegree()=0;
	virtual int getFeedDegree()=0;
	//名字确定
	virtual void theName(string&)=0;
	virtual void theSexy(int)=0;
	//数值检测改变
	virtual void seeWeight(int)=0;//超重
	virtual void seeFeed(int) = 0;//超喂食
	virtual void seeClean(int) = 0;//清洁度不足降低
	virtual void seeMood() = 0;
	//数值修改
	virtual void changeFeed(int, int) = 0;
	virtual void changeMood(int, int) = 0;
	virtual void changeWeight(int, int) = 0;
	virtual void changeClean(int, int) = 0;
	//重置！
	virtual void reset() = 0;
	//玩耍
	virtual void playPet() = 0;
	virtual void cleanPet() = 0;
	//猫的随机事件
	virtual void catRandomCatch()=0;
};

//宠物继承类
class Cat :public Pet {
public:
	Cat();
	//数值返回
	int getVary() {
		return vary;
	}
	int getSex() {
		return sex;
	}
	string getName() {
		return *name;
	}
	int getMoodDegree() {
		return moodDegree;
	}
	int getWeight() {
		return weight;
	}
	int getCleanDegree() {
		return cleanDegree;
	}
	int getFeedDegree() {
		return feedDegree;
	}
	//名字确定
	void theName(string&);
	void theSexy(int);
	//数值控制
	void seeWeight(int);
	void seeFeed(int);
	void seeClean(int);
	void seeMood();
	//数值修改
	void changeFeed(int, int);
	void changeMood(int, int);
	void changeWeight(int, int);
	void changeClean(int, int);
	//re
	void reset();
	//宠物关联
	void playPet();
	void cleanPet();
	//猫的随机事件
	void catRandomCatch();
};

class Dog :public Pet {
public:
	Dog();
	//数值返回
	int getVary() {
		return vary;
	}
	int getSex() {
		return sex;
	}
	string getName() {
		return *name;
	}
	int getMoodDegree() {
		return moodDegree;
	}
	int getWeight() {
		return weight;
	}
	int getCleanDegree() {
		return cleanDegree;
	}
	int getFeedDegree() {
		return feedDegree;
	}
	//名字确定
	void theName(string&);
	void theSexy(int);
	//数值控制
	void seeWeight(int);
	void seeFeed(int);
	void seeClean(int);
	void seeMood();
	//数值修改
	void changeFeed(int, int);
	void changeMood(int, int);
	void changeWeight(int, int);
	void changeClean(int, int);
	//re
	void reset();

	void playPet();
	void cleanPet();
	//猫的随机事件
	void catRandomCatch();
};

//外部相关//
//认养宠物
void raise();
//全局对象
Pet* ptr;
//system class
class System {
	friend class Player;
	friend class Pet;
private:
	int day=1;
public:
	//天数计数
	void daycount();
	//天数取得
	int getDay() {
		return day;
	}
	//存档
	void saveGame();
	//读档
	void loadGame();
	//重新开始
	void restart();
	//强制游戏结束(宠物挂了或逃跑)
	void forceGameDone();
	//游戏成功结束
	void goodEnding();
	//系统重置
	void reset() {
		day = 1;
	}
};
//外部控制
void systemSetting();
void gameExit();
void gameForceExit();
//全局对象
System sys;

void switchMoveMenu(char MenuWay) {
	switch (MenuWay)
	{
	case '1':
		//玩
		play();
		break;
	case '2':
		use();
		break;
	case '3':
		work();
		break;
	case '4':
		buy();
		break;
	case '5':
		rest();
		break;
	case '6':
		//清洁
		clean();
		break;
	case '7':
		sleep();
		break;
	case '8':
		systemSetting();
		break;
	case '9':
		gameExit();
		break;
	default:
		cout << "无此选项！！！" << endl;
		cout << "请重新选择！！！！" << endl;
		printDividerStar();
		char tempWay;
		cout << "输入选项:";
		cin >> tempWay;
		switchMoveMenu(tempWay);
	}
}

//认养宠物打印
void printRaise() {

	printLongStar();
	cout << endl;
	cout << "你现在需要认养一只宠物！！" << endl;
	cout << "如果你可以让宠物活过30天，则游戏胜利！" << endl;
	cout << "首先你想养猫还是养狗？" << endl;
	cout << "1.养猫 2.养狗" << endl;
	cout << "我选：";
	char id1; cin >> id1;
	switchChoosePet(id1);
	cout << "给你的宠物起个名字吧:";
	string tempName;
	cin >> tempName;
	ptr->theName(tempName);
	cout << "你想要公的还是母的呢" << endl;
	cout << "1.公 2.母" << endl;
	char id2; cin >> id2;
	switchSexyChoose(id2);
	cout << "成功领养宠物！" << endl;
	cout << "游戏正式开始" << endl;
	printDividerStar();
	cout << endl;
}

//短星号
void printShortStar() {
	cout << "*********************" << endl;
}
//长星号(后期再统一
void printLongStar() {
	cout << "**************************************" << endl;
}
//分割星号
void printDividerStar() {
	cout << "*******************************************************" << endl;
}
//打印进入头
void printHead() {
	printDividerStar();
	cout << endl;
	cout << "欢迎来到宠物游戏！" << endl;
	cout << "MADE IN 2019/12" << endl;
	cout << "首先请认养宠物" << endl;
	printDividerStar();
	cout << endl;
}

//主菜单
//每日主界面
void printMainMenu() {
	//天数打印
	cout << "          现在是第";
	cout << sys.getDay();
	cout << "天" << endl;
	//行动力打印
	cout << "          今天的剩余的行动力:";
	cout << player.showMovePoint();
	cout << endl;
	//金钱打印
	cout << "          你拥有的金钱:";
	cout << player.showMoney();
	cout << endl;
	//体力打印
	cout << "          体力:";
	cout << player.showPhy();
	cout << endl;
	//宠物姓名打印
	cout << "宠物名:";
	cout << ptr->getName();
	cout << "     ";
	//宠物性别打印
	cout << "性别:";
	if (ptr->getSex() == 1)
		cout << "公";
	else cout << "母";
	cout << "     ";
	//宠物品种打印
	cout << "宠物类型:";
	if (ptr->getVary() == 1)
		cout << "猫";
	else cout << "狗";
	cout << endl;
	//宠物饱食度
	cout << "饱食度:";
	cout << ptr->getFeedDegree();
	cout << "     ";
	//宠物愉悦度
	cout << "愉悦度:";
	cout << ptr->getMoodDegree();
	cout << "     ";
	//宠物体重
	cout << "体重:";
	cout << ptr->getWeight();
	cout << endl;
	//清洁度
	cout << "清洁度:";
	cout << ptr->getCleanDegree();
	cout << endl;
	//
	//行动菜单
	char MenuWay;
	printShortStar();
	cout << endl;
	cout << "您现在可以行动" << endl;
	cout << "1.和宠物玩耍     ";//5个空格
	cout << "2.向宠物投食     ";
	cout << "3.开始打工!     " << endl;
	cout << "4.买宠物粮食     ";
	cout << "5.累了休息会     ";
	cout << "6.清洁宠物吧     " << endl;
	cout << "7.直接睡觉，不管了  ";
	cout << "8.系统设置     ";
	cout << "9.不玩了！" << endl;
	cout << "做出你的选择:";
	cin >> MenuWay;
	switchMoveMenu(MenuWay);
}

//玩家类
/*
工作相关
*/
//工作逻辑
void switchWorkMenu(char id) {
	switch (id)
	{
	case '1':
		player.workHomeTea();
		break;
	case '2':
		player.workMc();
		break;
	case '3':
		player.workMow();
		break;
	case '4':
		printMainMenu();
		break;
	default:
		printShortStar();
		cout << endl;
		cout << "输入错误" << endl;
		cout << "请重新输入:";
		char newID;
		cin >> newID;
		switchWorkMenu(newID);
		break;
	}
}

//工作
void work() {
	printLongStar();
	cout << endl;
	cout << "看起来你没钱了，所以你要做什么工作？" << endl;
	cout << "1.我要去做家教(-2行动,+50金钱，-30体力)"<<endl;
	cout << "2.我想去金拱门收钱(-4行动,+120钱,-70体力)"<<endl;
	cout << "3.帮土豪的院子割草(-1行动,+20钱,-20体力)" << endl;
	cout << "4.返回主界面" << endl;
	cout << "请输入你的选择:";
	char workCh;
	cin >> workCh;
	switchWorkMenu(workCh);
}

void Player::workHomeTea() {
	if (movePoint >= 2 && phy >= 30) {
		printLongStar();
		cout << endl;
		cout << "消耗2行动力，获取50金钱，消耗30体力" << endl;
		movePoint -= 2;
		phy -= 30;
		money += 50;
		cout << "宠物清洁度下降20" << endl;
		ptr->changeClean(20, 0);
		cout << "宠物饱食度降低20" << endl;
		ptr->changeFeed(20, 0);
		cout << "宠物愉悦度降低10" << endl;
		ptr->changeMood(10, 0);
		ptr->seeClean(1);
		ptr->seeFeed(1);
		ptr->seeWeight(1);
		ptr->catRandomCatch();
		ptr->seeMood();
		work();
	}
	else {
		printLongStar();
		cout << endl;
		cout << "您的体力或行动力不足" << endl;
		cout << "将返回工作选择界面" << endl;
		work();
	}
}

void Player::workMc() {
	if (movePoint >= 4 && phy >= 70) {
		cout << "完成了在金拱门工作" << endl;
		cout << "消耗个4行动力，获取120金钱，消耗70体力" << endl;
		movePoint -= 4;
		phy -= 70;
		money += 120;
		cout << "宠物清洁度下降40" << endl;
		ptr->changeClean(40, 0);
		cout << "宠物饱食度降低20" << endl;
		ptr->changeFeed(20, 0);
		cout << "宠物愉悦度降低10" << endl;
		ptr->changeMood(10, 0);
		ptr->seeClean(1);
		ptr->seeFeed(1);
		ptr->seeWeight(1);
		ptr->catRandomCatch();
		ptr->seeMood();
		work();
	}
	else {
		printLongStar();
		cout << endl;
		cout << "您的体力或行动力不足" << endl;
		cout << "将返回工作选择界面" << endl;
		work();
	}
}

void Player::workMow() {
	if (movePoint >= 1 && phy >= 20) {
		cout << "给大户人家割完草" << endl;
		cout << "消耗1个行动力，获取20金钱，消耗20体力" << endl;
		movePoint -= 2;
		phy -= 30;
		money += 20;
		cout << "宠物清洁度下降10" << endl;
		ptr->changeClean(10, 0);
		cout << "宠物饱食度降20" << endl;
		ptr->changeFeed(20, 0);
		cout << "宠物愉悦度降低10" << endl;
		ptr->changeMood(10, 0);
		ptr->seeClean(1);
		ptr->seeFeed(1);
		ptr->seeWeight(1);
		ptr->catRandomCatch();
		ptr->seeMood();
		work();
	}
	else {
		printLongStar();
		cout << endl;
		cout << "您的体力或行动力不足" << endl;
		cout << "将返回工作选择界面" << endl;
		work();
	}
}

void buy() {
	printLongStar();
	cout << endl;
	cout << "你要去买一些宠物粮食" << endl;
	cout << "1.购买粗糙的粮食" << endl;
	cout << "2.购买精致的食物" << endl;
	cout << "3.购买火腿" << endl;
	cout << "4.没钱！回家算了" << endl;
	cout << "购买将会花费1个行动点与20体力"<<endl;
	cout << "选择选项:";
	char Id; cin >> Id;
	switchBuyFood(Id);
}

void switchBuyFood(char id) {
	switch (id)
	{
	case '1':
		player.buyRawFood();
		break;
	case '2':
		player.buyGoodFood();
		break;
	case '3':
		player.buyHuoTui();
		break;
	case '4':
		printMainMenu();
		break;
	default:
		printShortStar();
		cout << endl;
		cout << "输入错误" << endl;
		cout << "请重新输入:";
		char newID;
		cin >> newID;
		switchBuyFood(newID);
		break;
	}
}

void Player::buyRawFood() {
	if (money >= 30&&movePoint>=1) {
		cout << "成功购买粗糙的食物" << endl;
		rawFoodNum++;
		movePoint--;
		phy -= 20;
		cout << "宠物清洁度下降10" << endl;
		ptr->changeClean(10, 0);
		cout << "宠物饱食度降低20" << endl;
		ptr->changeFeed(20, 0);
		cout << "宠物愉悦度降低10" << endl;
		ptr->changeMood(10, 0);
		ptr->seeClean(1);
		ptr->seeFeed(1);
		ptr->seeWeight(1);
		ptr->catRandomCatch();
		ptr->seeMood();
		buy();
	}
	else {
		printLongStar();
		cout << endl;
		cout << "您的钞票不够，去打工吧或太晚了!" << endl;
		buy();
	}
}

void Player::buyGoodFood() {
	if (money >= 30 && movePoint >= 1) {
		cout << "成功购买精致的食物" << endl;
		goodFoodNum++;
		movePoint--;
		phy -= 20;
		cout << "宠物清洁度下降10" << endl;
		ptr->changeClean(10, 0);
		cout << "宠物饱食度降20" << endl;
		ptr->changeFeed(20, 0);
		cout << "宠物愉悦度降低10" << endl;
		ptr->changeMood(10, 0);
		ptr->seeClean(1);
		ptr->seeFeed(1);
		ptr->seeWeight(1);
		ptr->catRandomCatch();
		ptr->seeMood();
		buy();
	}
	else {
		printLongStar();
		cout << endl;
		cout << "您的钞票不够，去打工吧或太晚了!" << endl;
		buy();
	}
}

void Player::buyHuoTui() {
	if (money >= 30 && movePoint >= 1) {
		cout << "成功购买火腿" << endl;
		HuoTuiNum++;
		movePoint--;
		phy -= 20;
		cout << "宠物清洁度下降10" << endl;
		ptr->changeClean(10, 0);
		cout << "宠物饱食度降20" << endl;
		ptr->changeFeed(20, 0);
		cout << "宠物愉悦度降低10" << endl;
		ptr->changeMood(10, 0);
		ptr->seeClean(1);
		ptr->seeFeed(1);
		ptr->seeWeight(1);
		ptr->catRandomCatch();
		ptr->seeMood();
		buy();
	}
	else {
		printLongStar();
		cout << endl;
		cout << "您的钞票不够，去打工吧或太晚了!" << endl;
		buy();
	}
}

void rest() {
	cout << endl;
	printLongStar();
	cout << endl;
	cout << "是否休息？？" << endl;
	cout << "1.当然！要累死了啊" << endl;
	cout << "2.休息什么的不存在的(返回主菜单)" << endl;
	cout << "你选择：";
	char id;
	cin >> id;
	switch (id) {
	case '1':
		player.playerRest();
		break;
	case '2':
		printMainMenu();
		break;
	default:
		printShortStar();
		cout << endl;
		cout << "输入错误" << endl;
		cout << "返回休息菜单" << endl;
		rest();
		break;
	}
}

void Player::playerRest() {
	printShortStar();
	cout << endl;
	cout << "你休息了一会儿,感觉精力充沛" << endl;
	cout << "宠物清洁度下降10" << endl;
	ptr->changeClean(10, 0);
	cout << "宠物饱食度降20" << endl;
	ptr->changeFeed(20, 0);
	cout << "宠物愉悦度降低10" << endl;
	ptr->changeMood(10, 0);
	ptr->seeClean(1);
	ptr->seeFeed(1);
	ptr->seeWeight(1);
	ptr->catRandomCatch();
	ptr->seeMood();
	cout << "返回选择页面" << endl;
	rest();
}

void sleep() {
	printLongStar();
	cout << endl;
	cout << "是否睡觉？？" << endl;
	cout << "1.当然" << endl;
	cout << "2.算了，我要当熬夜冠军" << endl;
	char id; cin >> id;
	switch(id) {
	case '1':
		printShortStar();
		cout << endl;
		cout << "干啥啥不行，睡觉第一名，先睡觉再说" << endl;
		player.playerSleep();
		break;
	case '2':
		printMainMenu();
		break;
	default:
		printShortStar();
		cout << "输入错误！返回选择" << endl;
		sleep();
		break;
	}
}

void Player::playerSleep() {
	printLongStar();
	cout << endl;
	cout << "你睡的很好，一觉睡到了大天亮！(体力恢复，行动力恢复)" << endl;
	ptr->changeMood(30, 1);
	ptr->changeClean(10, 0);
	ptr->changeFeed(60, 0);
	cout << "宠物降低60饱食度，10清洁度，愉悦度上升30" << endl;
	sys.daycount();
	//包含随机事件打印调用
	phy = 100;
	movePoint = 7;
	ptr->seeClean(1);
	ptr->seeFeed(1);
	ptr->seeWeight(1);
	ptr->catRandomCatch();
	ptr->seeMood();
	system("pause");
	system("cls");
	printMainMenu();
	//maybe correct
}

/*
系统控制函数
*/
//
//存档读档暂无//
//fstream待实现
void systemSetting() {
	printLongStar();
	cout << endl;
	cout << "1.游戏存档" << endl;
	cout << "2.游戏读档" << endl;
	cout << "3.重新开始" << endl;
	cout << "输入你的选择:";
	char id;
	cin >> id;
	switchSystemFun(id);
}

void switchSystemFun(char id) {
	switch (id)
	{
	case '1':
		sys.saveGame();//
		break;
	case '2':
		sys.loadGame();//
		break;
	case '3':
		sys.restart();
		break;
	default:
		printShortStar();
		cout << endl;
		cout << "输入错误,重新选择:" << endl;
		char newid;
		cin >> newid;
		switchSystemFun(newid);
		break;
	}
}

void gameExit() {
	printDividerStar();
	cout << "退出将不会保存游戏数据，是否退出？？" << endl;
	cout << "1.是 2.否" << endl;
	char id;
	cin >> id;
	if (id == '1') {
		exit(0);
	}
	else if (id == '2') {
		return;
		printMainMenu();
	}
	else {
		printLongStar();
		cout << endl;
		cout << "输入非法!!" << endl;
		gameExit();
	}
}

void System::restart() {
	cout << "您要重新开始吗？？" << endl;
	cout << "1.是 2.否" << endl;
	char id;
	cin >> id;
	if (id == '1') {
		system("cls");
		player.reset();
		sys.reset();	
		//宠物重置
		ptr->reset();
		cout << "游戏重置成功" << endl;
		printDividerStar();
		cout << endl;
		printMainMenu();
	}
	if (id == '2') {
		return;
	}
	else {
		printShortStar();
		cout << endl;
		cout << "输入错误" << endl;
		restart();
	}
}

void System::daycount() {
first:
	day++;
	if (day == 31) {
		printDividerStar();
		cout << "成功让宠物活过30天！" << endl;
		cout << "您可以继续游戏或者重新开始或者直接退出游戏" << endl;
		cout << "1.重新开始" << endl;
		cout << "2.继续游戏" << endl;
		cout << "3.退出游戏" << endl;
		cout << "做出你的选择:" << endl;
		char id;
		cin >> id;
		switch (id)
		{
		case '1':
			sys.restart();
			break;
		case '2':
			printMainMenu();
			break;
		case '3':
			gameExit();
			break;
		default:
			goto first;
			break;
		}
	}
}

void gameForceExit() {
	system("cls");
	cout << "看来你的宠物逃跑或者死亡了" << endl;
	cout << "你要1.重新开始 2.读取存档 3.不玩了:" << endl;
	char id; cin >> id;
	switch (id)
	{
	case '1':
		sys.restart();
		break;
	case '2':
		sys.loadGame();
		break;
	default:
		cout << "输入错误！" << endl;
		cout << "直接退出游戏了！！" << endl;
		exit(0);
	}
}

void System::loadGame() {

}

void System::saveGame() {

}

/*
宠物行为函数等定义
*/
void switchChoosePet(char id) {
	switch (id)
	{
	case '1':
		ptr = new Cat;
		break;
	case '2':
		ptr = new Dog;
		break;
	default:
		cout << "选的啥？再选一次:";
		char newid;
		cin >> newid;
		switchChoosePet(newid);
		break;
	}
}
//宠物性别选择
void switchSexyChoose(char id) {
	switch (id)
	{
	case '1':
		ptr->theSexy(1);
		break;
	case '2':
		ptr->theSexy(2);
		break;
	default:
		cout << "选择错误重新选择:";
		char newid;
		cin >> newid;
		switchSexyChoose(newid);
		break;
	}
}

//性别确定与名字确定
void Cat::theSexy(int temp) {
	sex = temp;
	if (sex == 1) {
		weight = 10;
	}
	else {
		weight = 6;
	}
}

void Dog::theSexy(int temp) {
	sex = temp;
	weight = 45;
}
void Cat::theName(string& str) {
	name = new string;
	*name = str;
}

void Dog::theName(string& str) {
	*name = str;
}
//构造函数
Cat::Cat() {
	vary = 1;
	name = NULL;
	weight = 10;
	feedDegree = 50;
	moodDegree = 50;
	cleanDegree = 50;
	cleanDay = 0;
	lastDay = 0;
	cleanTime = 1;
}

Dog::Dog() {
	vary = 2;
	name = NULL;
	weight = 10;
	feedDegree = 50;
	moodDegree = 50;
	cleanDegree = 50;
	cleanDay = 0;
	lastDay = 0;
	cleanTime = 1;
}
//数值修改
//temp为0时为减少 其他为增加
void Cat::changeClean(int num,int temp) {
	if (temp == 0) {
		cleanDegree -= num;
		if (cleanDegree <= 0)
			cleanDegree = 0;
	}
	else {
		cleanDegree += num;
		if (cleanDegree >= 100)
			cleanDegree = 100;
	}
}
void Cat::changeFeed(int num, int temp) {
	if (temp == 0) {
		feedDegree -= num;
		if (feedDegree <= 0)
			feedDegree = 0;
	}
	else {
		feedDegree += num;
		if (feedDegree >= 100)
			feedDegree = 100;
	}
}
void Cat::changeMood(int num, int temp) {
	if (temp == 0) {
		moodDegree -= num;
		if (moodDegree <= 0)
			moodDegree = 0;
	}
	else {
		moodDegree += num;
		if (moodDegree >= 100)
			moodDegree = 100;
	}
}
void Cat::changeWeight(int num, int temp) {
	if (temp == 0)
		weight -= num;
	else
		weight += num;
}

void Dog::changeClean(int num, int temp) {
	if (temp == 0) {
		cleanDegree -= num;
		if (cleanDegree <= 0)
			cleanDegree = 0;
	}
	else {
		cleanDegree += num;
		if (cleanDegree >= 100)
			cleanDegree = 100;
	}
}
void Dog::changeFeed(int num, int temp) {
	if (temp == 0) {
		feedDegree -= num;
		if (feedDegree <= 0)
			feedDegree = 0;
	}
	else {
		feedDegree += num;
		if (feedDegree >= 100)
			feedDegree = 100;
	}
}
void Dog::changeMood(int num, int temp) {
	if (temp == 0) {
		moodDegree -= num;
		if (moodDegree <= 0)
			moodDegree = 0;
	}
	else {
		moodDegree += num;
		if (moodDegree >= 100)
			moodDegree = 100;
	}
}
void Dog::changeWeight(int num, int temp) {
	if (temp == 0)
		weight -= num;
	else
		weight += num;
}
//清洁度检测
void Cat::seeClean(int point) {
	if (ptr->getCleanDegree() == 0) {
		printShortStar();
		cout << endl;
		changeMood(10 * point, 0);
		cout << "清洁度为0！！减少愉悦度" << 10 * point << endl;
		printShortStar();
		cout << endl;
	}
	if (ptr->getCleanDegree() >= 70) {
		printShortStar();
		cout << endl;
		changeMood(10 * point, 0);
		cout << "清洁度高于70！！增加愉悦度" << 10 * point << endl;
		printShortStar();
		cout << endl;
	}
	else return;
}
void Dog::seeClean(int point) {
	if (ptr->getCleanDegree() == 0) {
		changeMood(10 * point, 0);
		printShortStar();
		cout << endl;
		cout << "清洁度为0！！减少清洁度" << 10 * point << endl;
		printShortStar();
		cout << endl;
	}
	if (ptr->getCleanDegree() >= 70) {
		printShortStar();
		cout << endl;
		changeMood(10 * point, 0);
		cout << "清洁度高于70！！增加愉悦度" << 10 * point << endl;
		printShortStar();
		cout << endl;
	}
	else return;
}
//体重检测 1公
void Cat::seeWeight(int point) {
	if (sex == 1 && ptr->getWeight() >= 4 && 8 >= ptr->getWeight()) {
		printShortStar();
		cout << endl;
		changeMood(10 * point, 0);
		cout << "体重过轻！减少" << point * 10 << "愉悦度" << endl;
		printShortStar();
		cout << endl;
	}
	else if (sex == 0 && ptr->getWeight() >= 2 && 4 >= ptr->getWeight()) {
		printShortStar();
		cout << endl;
		changeMood(10 * point, 0);
		cout << "体重过轻！减少" << point * 10 << "愉悦度" << endl;
		printShortStar();
		cout << endl;
	}
	else if (sex == 1 && ptr->getWeight() >= 12 && 16 >= ptr->getWeight()) {
		printShortStar();
		cout << endl;
		changeMood(10 * point, 0);
		cout << "体重过重！减少" << point * 10 << "愉悦度" << endl;
		printShortStar();
		cout << endl;
	}
	else if (sex == 0 && ptr->getWeight() >= 8 && 10 >= ptr->getWeight()) {
		printShortStar();
		cout << endl;
		changeMood(10 * point, 0);
		cout << "体重过重！减少" << point * 10 << "愉悦度" << endl;
		printShortStar();
		cout << endl;
	}
	else if (sex == 1) {
		if (ptr->getWeight() < 4 || ptr->getWeight() > 16) {
			printDividerStar();
			cout << endl;
			cout << "你的宠物因为体重健康状况低下死亡" << endl;
			gameForceExit();
		}
		else if (sex == 0) {
			if (ptr->getWeight() < 2 || ptr->getWeight()>10) {
				printDividerStar();
				cout << endl;
				cout << "你的宠物因为体重健康状况低下死亡" << endl;
				gameForceExit();
			}
		}
	}
	else return;
}

void Dog::seeWeight(int point) {
	if (ptr->getWeight() >= 15 && ptr->getWeight() <= 30) {
		printShortStar();
		cout << endl;
		changeMood(10 * point, 0);
		cout << "体重过轻！减少" << point * 10 << "愉悦度" << endl;
		printShortStar();
		cout << endl;
	}
	if (ptr->getWeight() >= 60 && ptr->getWeight() <= 75) {
		printShortStar();
		cout << endl;
		changeMood(10 * point, 0);
		cout << "体重过重！减少" << point * 10 << "愉悦度" << endl;
		printShortStar();
		cout << endl;
	}
	if (ptr->getWeight() > 75 || ptr->getWeight() < 30) {
		printDividerStar();
		cout << endl;
		cout << "你的宠物因为体重健康状况低下死亡" << endl;
		gameForceExit();
	}
	else return;
}

//饱食度监测
void Cat::seeFeed(int point) {
	if (ptr->getFeedDegree() == 0) {
		printShortStar();
		cout << endl;
		ptr->changeMood(10, 0);
		ptr->changeWeight(1, 0);
		cout << "宠物饱食度不足为0减少愉悦值10,1体重" << endl;
		printShortStar();
		cout << endl;
	}
	if (ptr->getFeedDegree() == 100) {
		printShortStar();
		cout << endl;
		ptr->changeWeight(1, 1);
		cout << "饱食度100，体重增加1" << endl;
		printShortStar();
		cout << endl;
	}
	else return;
}

void Dog::seeFeed(int point) {
	if (ptr->getFeedDegree() ==0) {
		printShortStar();
		cout << endl;
		ptr->changeMood(10, 0);
		ptr->changeWeight(1, 0);
		cout << "宠物饱食度不足为0减少愉悦值10,1体重" << endl;
		printShortStar();
		cout << endl;
	}
	if (ptr->getFeedDegree() == 100) {
		printShortStar();
		cout << endl;
		ptr->changeWeight(2, 1);
		cout << "饱食度100，体重增加2" << endl;
		printShortStar();
		cout << endl;
	}
	else return;
}

void Cat::seeMood() {
	if (ptr->getMoodDegree() == 0) {
		gameForceExit();
	}
	else return;
}

void Dog::seeMood() {
	if (ptr->getMoodDegree() == 0) {
		gameForceExit();
	}
	else return;
}

void Cat::reset() {
	weight = 10;
	feedDegree = 50;
	moodDegree = 50;
	cleanDegree = 50;
	cleanDay = 0;
	vary = 1;
}

void Dog::reset() {
	weight = 10;
	feedDegree = 50;
	moodDegree = 50;
	cleanDegree = 50;
	cleanDay = 0;
	vary = 2;
}
/*
玩家与宠物交互函数
*/

void use() {
	printLongStar();
	cout << endl;
	cout << "你想给宠物投食吗?" << endl;
	cout << "当前拥有食物:" << endl;
	cout << "粗糙的食物(为宠物提供30体力，10愉悦度，降低15清洁度)" << player.showRaw() << "个" << endl;
	cout << "精致的食物(为宠物提供50体力，40愉悦度，降低5清洁度)" << player.showGood() << "个" << endl;
	cout << "火腿(为宠物提供20体力，30愉悦度，降低20清洁度)" << player.showHuo() << "个" << endl;
	cout << "1.我想喂食!!(消耗1个行动力，20体力)" << endl;
	cout << "2.算了(返回主菜单)" << endl;
	char chooseid;
	cout << "做出你的选择："; cin >> chooseid;
	if (chooseid == '1') {
		cout << endl;
		printShortStar();
		cout << endl;
		cout << "你想喂食什么？？(1,2,3):" << endl;
		char id;
		cin >> id;
		switchFeedFun(id);
	}
	else if (chooseid == '2') {
		printMainMenu();//疑问?
		//switchMainFun(
	}
	else {
		printLongStar();
		cout << "输入错误！！返回喂食菜单" << endl;
		use();
	}
}

void switchFeedFun(char id) {
	switch (id)
	{
	case '1': 
		player.useRaw();
		break;
	case '2':
		player.useGood();
		break;
	case '3':
		player.useHuo();
		break;
	default:
		printShortStar();
		cout << endl;
		cout << "输入错误" << endl;
		cout << "请重新输入:";
		char newID;
		cin >> newID;
		switchFeedFun(newID);
		break;
	}
}

//喂食
void Player::useRaw() {
	if (rawFoodNum >= 1&&phy>=20&&movePoint>=1) {
		printLongStar();
		cout << endl;
		cout << "喂食成功！！！" << endl;
		cout << "为宠物提供30饱食度，10愉悦度，降低20清洁度" << endl;
		cout << "减少1个粗糙食物,20体力，1行动力" << endl;
		ptr->changeFeed(30, 1);
		ptr->changeMood(10, 1);
		ptr->changeClean(20, 0);
		rawFoodNum--;
		phy -= 20;
		movePoint -= 1;
		ptr->seeClean(1);
		ptr->seeFeed(1);
		ptr->seeWeight(1);
		ptr->catRandomCatch();
		ptr->seeMood();
		use();
	}
	else {
		printLongStar();
		cout << endl;
		cout << "无法喂食，物品不足或体力不足或行动力不足" << endl;
		use();
	}
}

void Player::useGood() {
	if (goodFoodNum >= 1 && phy >= 20 && movePoint >= 1) {
		printLongStar();
		cout << endl;
		cout << "喂食成功！！！" << endl;
		cout << "为宠物提供50饱食度，40愉悦度，降低10清洁度" << endl;
		cout << "减少1个精致食物,20体力，1行动力" << endl;
		ptr->changeFeed(50, 1);
		ptr->changeMood(40, 1);
		ptr->changeClean(10, 0);
		rawFoodNum--;
		phy -= 20;
		movePoint -= 1;
		ptr->seeClean(1);
		ptr->seeFeed(1);
		ptr->seeWeight(1);
		ptr->catRandomCatch();
		ptr->seeMood();
		use();
	}
	else {
		printLongStar();
		cout << endl;
		cout << "无法喂食，物品不足或体力不足或行动力不足" << endl;
		use();
	}
}

void Player::useHuo() {
	if (HuoTuiNum >= 1 && phy >= 20 && movePoint >= 1) {
		printLongStar();
		cout << endl;
		cout << "喂食成功！！！" << endl;
		cout << "为宠物提供20饱食度，30愉悦度，降低20清洁度" << endl;
		cout << "减少1个火腿,20体力，1行动力" << endl;
		ptr->changeFeed(20, 1);
		ptr->changeMood(30, 1);
		ptr->changeClean(20, 0);
		rawFoodNum--;
		phy -= 20;
		movePoint -= 1;
		ptr->seeClean(1);
		ptr->seeFeed(1);
		ptr->seeWeight(1);
		ptr->catRandomCatch();
		ptr->seeMood();
		use();
	}
	else {
		printLongStar();
		cout << endl;
		cout << "无法喂食，物品不足或体力不足或行动力不足" << endl;
		use();
	}
}


//玩耍
void play() {
	printLongStar();
	cout << endl;
	cout << "是否和宠物玩耍？？(消耗1个行动力和30体力)" << endl;
	cout << "和狗玩耍消耗30点饱食度，提高40点愉悦度，降低10点清洁度。" << endl;
	cout << "你要和猫玩耍(会消耗20点饱食度，提高30点愉悦度（猫是高冷的），降低10点清洁度。)"<<endl;
	cout << "1.是 2.返回" << endl;
	cout << "你选择:";
	char id;
	cin >> id;
	if (id == '1') {
		ptr->playPet();
	}
	if (id == '2') {
		printMainMenu();
	}
	else {
		cout << "输入错误！" << endl;
		play();
	}
}

void Cat::playPet() {
	printLongStar();
	cout << endl;
	cout << "你和宠物开心玩了一会" << endl;
	ptr->changeMood(30, 1);
	ptr->changeFeed(20, 0);
	ptr->changeClean(10, 0);
	ptr->seeClean(1);
	ptr->seeFeed(1);
	ptr->seeWeight(1);
	ptr->catRandomCatch();
	ptr->seeMood();
	player.playPlayer();
	play();
}

void Dog::playPet() {
	printLongStar();
	cout << endl;
	cout << "你要和狗玩耍"<<endl;
	cout << "你和宠物开心玩了一会" << endl;
	ptr->changeMood(40, 1);
	ptr->changeFeed(30, 0);
	ptr->changeClean(10, 0);
	ptr->seeClean(1);
	ptr->seeFeed(1);
	ptr->seeWeight(1);
	ptr->catRandomCatch();
	ptr->seeMood();
	player.playPlayer();
	play();
}

void Player::playPlayer() {
	phy -= 30;
	movePoint--;
}

//清洁
void clean() {
	printLongStar();
	cout << endl;
	cout << "你是否要清洁宠物？？" << endl;
	cout << "玩家消耗1个行动点，30体力。" << endl;
	cout << "提高100清洁度。" << endl;
	cout << "对于猫，清洁度高于80或清洁间隔低于28个时间段时，不接受被主人清洁，强行清洁会降低50愉悦度" << endl;
	cout << "1.是 2.否" << endl;
	cout << "你选择:";
	char id;
	cin >> id;
	if (id == '1') {
		ptr->cleanPet();
	}
	if (id == '2') {
		printMainMenu();
	}
	else {
		cout << "输入错误！！" << endl;
		clean();
	}
}

void Player::cleanPlayer() {
	phy -= 30;
	movePoint--;
}

void Cat::cleanPet() {
	if (cleanTime == 1) {
		cleanDay = sys.getDay();
		printLongStar();
		cout << endl;
		cout << "你确定要清洁宠物猫吗？" << endl;
		cout << "对于猫，清洁度高于80或清洁间隔低于28个时间段时，不接受被主人清洁，强行清洁会降低40愉悦度" << endl;
		cout << "当前宠物猫的清洁度:" << ptr->getCleanDegree() << endl;
		cout << "当前宠物猫的清洁间隔天数:0" << endl;
		cout << "是否清洁？" << endl;
		cout << "1.是 2.否" << endl;
		cout << "所以:";
		char id; cin >> id;
		if (id == '1') {
			if (ptr->getCleanDegree() > 80) {
				cleanDay = sys.getDay();
				lastDay = sys.getDay();
				ptr->changeClean(100, 1);
				ptr->changeMood(40, 0);
				player.cleanPlayer();
				player.cleanPlayer();
				ptr->seeClean(1);
				ptr->seeFeed(1);
				ptr->seeWeight(1);
				ptr->seeMood();
				cleanTime++;
			}
			else {
				ptr->changeClean(100, 1);
				player.cleanPlayer();
				ptr->seeClean(1);
				ptr->seeFeed(1);
				ptr->seeWeight(1);
				ptr->seeMood();
				cleanTime++;
			}
			printMainMenu();
		}
		if (id == '2') {
			printMainMenu();
		}
	}
	else {
		cleanDay = sys.getDay();
		printLongStar();
		cout << endl;
		cout << "你确定要清洁宠物猫吗？" << endl;
		cout << "对于猫，清洁度高于80或清洁间隔低于28个时间段时，不接受被主人清洁，强行清洁会降低40愉悦度" << endl;
		cout << "当前宠物猫的清洁度:" << ptr->getCleanDegree() << endl;
		cout << "当前宠物猫的清洁间隔天数" << cleanDay - lastDay;
		cout << "是否清洁？" << endl;
		cout << "1.是 2.否" << endl;
		cout << "所以:";
		char id; cin >> id;
		if (id == '1') {
			if (ptr->getCleanDegree() > 80) {
				cleanDay = sys.getDay();
				lastDay = sys.getDay();
				ptr->changeClean(100, 1);
				ptr->changeMood(40, 0);
				player.cleanPlayer();
				player.cleanPlayer();
				ptr->seeClean(1);
				ptr->seeFeed(1);
				ptr->seeWeight(1);
				ptr->seeMood();
				cleanTime++;
				printMainMenu();
			}
			else {
				ptr->changeClean(100, 1);
				player.cleanPlayer();
				ptr->seeClean(1);
				ptr->seeFeed(1);
				ptr->seeWeight(1);
				ptr->seeMood();
				cleanTime++;
				clean();
			}
			printMainMenu();
		}
		if (id == '2') {
			printMainMenu();
		}
	}
}

void Dog::cleanPet() {
	printLongStar();
	cout << endl;
	cout << "你成功清洁狗" << endl;
	player.cleanPlayer();
	ptr->changeClean(100, 1);
	ptr->seeClean(1);
	ptr->seeFeed(1);
	ptr->seeWeight(1);
	ptr->seeMood();
	clean();
}

//猫独立
void Cat::catRandomCatch() {
	printShortStar();
	cout << endl;
	srand((int)time(0));
	if (rand() % 100 <= 20) {
		cout << "猫在你离开时随机抓了老鼠" << endl;
		if (ptr->getFeedDegree() <= 50) {
			cout << "猫吃掉了老鼠" << endl;
			cout << "提高40饱食度" << endl;
			cout << "降低30清洁度" << endl;
			cout << "提高10愉悦度" << endl;
			ptr->changeFeed(40, 1);
			ptr->changeClean(30, 0);
			ptr->changeMood(10, 1);
			ptr->seeClean(1);
			ptr->seeFeed(1);
			ptr->seeWeight(1);
			ptr->seeMood();
		}
		else {
			cout << "猫戏耍了老鼠" << endl;
			cout << "提高40愉悦度" << endl;
			cout << "降低10清洁度" << endl;
			cout << "降低20饱食度" << endl;
			ptr->changeFeed(20, 0);
			ptr->changeClean(10, 0);
			ptr->changeMood(40, 1);
			ptr->seeClean(1);
			ptr->seeFeed(1);
			ptr->seeWeight(1);
			ptr->seeMood();
		}
	}
	else return;
}

void Dog::catRandomCatch() {
	return;
}

int main() {
	printHead();
	printRaise();
	while (true) {
		printMainMenu();
	}
	return 0;
}
