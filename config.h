#ifndef CONFIG_H
#define CONFIG_H

/*****游戏配置数据******/
#define GAME_WIDTH 800
#define GAME_HEHGHT 1200
#define MAP_WIDTH 670
#define MAP_HEIGHT 1225
#define GAME_TITLE "程设通天路 DogeJumpToSky"
#define GAME_RATE 10 //定时器刷新时间间隔（单位为毫秒
/*****icon配置数据*****/
#define GAME_ICON  ":/new/prefix1/res/doge.png"
/*****地图配置数据*****/
#define MAP_PATH ":/new/prefix1/res/background1.png"
/*****主菜单配置数据*****/
#define START_ICON_PATH ":/new/prefix1/res/icon2.png"
#define START_TITLE_PATH ":/new/prefix1/res/start_title_.png"
#define START_BG_PATH ":/new/prefix1/res/start_bg.jpeg"
#define START_INFO_PATH ":/new/prefix1/res/info_.png"
/*****doge配置数据*****/
#define HERO_PATH ":/new/prefix1/res/hero_doge.png"
/*****板块配置数据*****/
#define BOARD_WIDTH 180
#define BOARD_HEIGHT 50
#define BOARD_NUM 9
#define X_INTERVAL 64
#define Y_INTERVAL 133
/*****AC板配置数据*****/
#define ACBOARD_PATH ":/new/prefix1/res/ac_.png"
/*****WA板配置数据*****/
#define WABOARD_PATH ":/new/prefix1/res/wa_.png"
#define WA_PIECE1_PATH ":/new/prefix1/res/wa_piece1.png"
#define WA_PIECE2_PATH ":/new/prefix1/res/wa_piece2.png"
/*****PASSED板配置数据*****/
#define PASS_BOARD_PATH ":/new/prefix1/res/pass_.png"
/*****CE板配置数据*****/
#define CEBOARD_PATH ":/new/prefix1/res/ce_.png"
/*****弹簧配置数据*****/
#define SPRING_PATH ":/new/prefix1/res/spri.png"
/*****音效配置数据*****/
#define SOUND_BACKGROUND ":/new/prefix1/res/bk.wav"
#define SOUND_BOMB ":/new/prefix1/res/short.wav"
#define SOUND_BACKGROUND_START ":/new/prefix1/res/bg.mp3"
/*****子场景配置数据*****/
#define GAMEVIEW_WIDTH 660
#define GAMEVIEW_HEIGHT 1200
/*****timer配置数据*****/
#define KEY_REPEAT_RATE 12
/*****镜头移动配置数据*****/
#define MOVE_THRESH 580
#define BOTTON_CONFIG "QPushButton{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: none;}""QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}""QPushButton:pressed{background-color:rgb(204, 228, 247);}"
/*****结束界面配置数据*****/
#define END_BG_PATH ":/new/prefix1/res/end_bg.png"
/*****干扰物配置数据*****/
#define BARRIER_PATH ":/new/prefix1/res/502.png"
#define BARRIER_LEN 75
/*****Boss配置数据*****/
#define BOSS_PATH ":/new/prefix1/res/boss.png"
/*****小怪配置数据*****/
#define MONSTER_PATH ":/new/prefix1/res/sprite_monster.png"
#define MONSTER_HEIGHT 50
#define MONSTER_WIDTH 50
#define MONSTER_X_INTERVAL 25
#define MONSTER_Y_INTERVAL 600
#define MONSTER_NUM 1

#endif // CONFIG_H
