JQK以JQK表示:如黑桃Q則牌為:[QS]，值為10，另外1僅代表1，不代表11

玩法:

首先我會詢問參加人數

1.How many human?代表有幾個真人(>=0)
假如為2
那麼我會分別問:
(1)What's Human name?->打該人名字
(2)What's Human bankroll?->這個人的存款

2.然後How many Meek computer?->問Meek 電腦有幾個
(1)What's Meek computer name?->名字
(2)What's Meek computerbankroll?->存款


3.How many Random computer?(>=0)問Random 電腦有幾個
(1)What's Meek computer name?->名字
(2)What's Meek computerbankroll?->存款



以	型態        		姓名           賭款
        Human       		Bob            100
	Meek computer   	Mike           300
	Random computer  	Rob	       400
為例:

莊家型態	姓名		賭款

Dealer		Dealer 		10000

4.接著開始遊戲，印出:
Okay, time for betting!
--------------------------------
然後我會依序問每個真人要賭的賭的金錢數量，以Bob為名的真人為例:
Bob, how much would you like to bet?(>=1)
而其他電腦賭的金錢則按造ppt所建構
Meek computer為2，連續贏3場後變兩倍
Random computer 1~一半的隨機

5.所有人確定賭數後印出一開始的排，第一張為暗牌([??])，第二張為明牌(其中明牌JQK直接印出來加上花色)
先印出:
The initial starting cards are:
-----------------------------------------
然後依序:
Bob's current hand[??][QD] 
Mike's current hand[??][10H]
Rob's current hand[??][5C]
Dealer's current hand[??][6C]

6.因為Bob是真人，我們在其回合的時候會詢問是否繼續抽(其中1的值在這場遊戲中僅代表1，不能為11)

Bob's current hand[AS][QD](11 point)
Would you like to draw another card?(Y or N):->要繼續抽打Y，不要則打N，以Y為例:
印出:
Bob chooses to draw.
然後印出新的牌序:
Bob's current hand[AS][QD][KD](21 point)
之後再詢問一遍
Would you like to draw another card?(Y or N):->此時我選N:
印出:
Bob chooses to stay.
如果爆牌，例:
Bob's current hand[QS][QD][KD](30 point)
會印出:
Bob busted at 23!

之後電腦的抽牌方式則按造作業規則

Meek:
合計偶數抽
合計基數不抽


Random:
合計<=12->80%機率抽
合計>=13且<=15->70%機率抽
合計>=16且<=18->50%機率抽
>=19->不抽

Dealer:
<=16抽
>=17不抽

之後找出所有參加者之最大者(如果同時超過兩人有最大值，則所有人皆輸，唯獨Dealer贏)


以
Bob           21點(賭50)    存款:100
Mike          15點(賭2)     存款:300
Rob           17點(賭11)    存款:400
Dealer        爆牌          存款:10000
為例
	 
此場中，Bob最大->獲勝，印出:
Yowzah! Bob wins $ 50
其他兩位電腦輸，印出:
Ouch! Mike loses $ 2
Ouch! Rob loses $ 11


而50-2-11 = 37->莊家虧損37，在計算過後印出:
The standings so far:
------------------------------
Bob $ 150
Mike $ 298
Rob $ 389
Dealer $ 9963


最後詢問:Another round? (Y or N):詢問是繼續玩，而存款保持不變

如果打Y->繼續玩
如果打N->結束程式




