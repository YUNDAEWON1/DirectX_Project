#include "Include.h"
#include <iostream>

enum {MAX_SPAWN_COUNT=1};

Enemy eTank1, eTank2;

Enemy::Enemy()
{
    enemyState = down;
   
}
Enemy::~Enemy()
{

}
void Enemy::Reset()
{
}
void Enemy::Init()
{
    eTank1.nowx = 28;
    eTank1.nowy = 32;

    eTank2.nowx = 605;
    eTank2.nowy = 32;

    speed = 2.f;
    eTank1.isDead = FALSE;
    eTank2.isDead = FALSE;


    respawnCount2 = 0;
    respawnCount1 = 0;

    enemyState = STATE::start;
    eTank1.AniFlame = 0;
    eTank1.AniTime = GetTickCount64();
    eTank1.DieTime = GetTickCount64();

    eTank2.AniFlame = 0;
    eTank2.AniTime = GetTickCount64();
    eTank2.DieTime = GetTickCount64();

    char Filename[256];

    sprintf_s(Filename, "./resource/Img/enemy/enemy1_down_00.png");
    eTank1.enemy1[0].Create(Filename, true, D3DCOLOR_XRGB(0, 128, 128));
    colider1.Create("./resource/Img/BATTLECITY/colider1.png", true, RGB(255, 255, 255));

    


    sprintf_s(Filename, "./resource/Img/enemy/enemy2_down_00.png");
    eTank2.enemy2[0].Create(Filename, true, D3DCOLOR_XRGB(0, 128, 128));
    colider2.Create("./resource/Img/BATTLECITY/colider1.png", true, RGB(255, 255, 255));

    SetRect(&eTank1.enemy1Colider, eTank1.nowx, eTank1.nowy, eTank1.nowx + 43, eTank1.nowy + 43);
    SetRect(&eTank2.enemy2Colider, eTank2.nowx, eTank2.nowy, eTank2.nowx + 43, eTank2.nowy + 43);

}


void Enemy::eTank1Move(double left,double right,double up,double down) {
    //////////////////////////�� ��ũ�� ȭ�� ���� �浹 ó��///////////////////////////////////

    if (eTank1.isDead == FALSE)
    {
        // ���� ��ġ�� ����
        RECT prevColider = eTank1.enemy1Colider;

        // �̵��Ϸ��� ��ġ ���
        double next_left = eTank1.nowx - left * speed;
        double next_right = eTank1.nowx + 43 + right * speed;
        double next_top = eTank1.nowy - up * speed;
        double next_bottom = eTank1.nowy + 43 + down * speed;

        // �̵��Ϸ��� ��ġ�� ��ȿ���� �˻�
        if (next_left < 24 || next_right > 651 || next_top < 29 || next_bottom > 650) {
            // ��ȿ�� ��ġ�� �ƴϸ� �̵����� ����
            return;
        }

        ////////////////////////////����ũ�� ��Ÿ���� �浹ó��/////////////////////////////////

        // eTank1 ��ũ �浹 ó��
        RECT nextColider;
        SetRect(&nextColider, eTank1.nowx - left * speed, eTank1.nowy - up * speed, eTank1.nowx + 43 + right * speed, eTank1.nowy + 43 + down * speed);
        if (nextColider.left < 24 || nextColider.right > 651 || nextColider.top < 29 || nextColider.bottom > 650) {
            // ��ȿ�� ��ġ�� �ƴϸ� �浹 ó������ ����
            return;
        }
        for (int row = 0; row < 26; row++) {
            for (int col = 0; col < 26; col++) {
                if (map.map[row][col] != 0) {
                    SetRect(&map.TileRect[row][col], 24 + col * 24, 28 + row * 24, 24 + col * 24 + 24, 28 + row * 24 + 24);
                    RECT intersection;
                    if (IntersectRect(&intersection, &nextColider, &map.TileRect[row][col])) {
                        return;
                    }
                }
            }
        }
        // �̵� ������ ��� ��ũ�� ��ġ�� ������Ʈ

        //eTank1
        eTank1.nowy -= up * speed;
        eTank1.nowy += down * speed;
        eTank1.nowx += right * speed;
        eTank1.nowx -= left * speed;
        SetRect(&eTank1.enemy1Colider, eTank1.nowx, eTank1.nowy, eTank1.nowx + 43, eTank1.nowy + 43);
    }
    
}

void Enemy::eTank2Move(double left, double right, double up, double down)
{

    if (eTank2.isDead == FALSE)
    {
        // ���� ��ġ�� ����
        RECT prevColider2 = eTank2.enemy2Colider;

        // �̵��Ϸ��� ��ġ ���
        double next_left2 = eTank2.nowx - left * speed;
        double next_right2 = eTank2.nowx + 43 + right * speed;
        double next_top2 = eTank2.nowy - up * speed;
        double next_bottom2 = eTank2.nowy + 43 + down * speed;

        // �̵��Ϸ��� ��ġ�� ��ȿ���� �˻�
        if (next_left2 < 24 || next_right2 > 651 || next_top2 < 29 || next_bottom2 > 650) {
            // ��ȿ�� ��ġ�� �ƴϸ� �̵����� ����
            return;
        }

        // eTank2 ��ũ �浹 ó��
        RECT nextColider;
        SetRect(&nextColider, eTank2.nowx - left * speed, eTank2.nowy - up * speed, eTank2.nowx + 43 + right * speed, eTank2.nowy + 43 + down * speed);
        for (int row = 0; row < 26; row++) {
            for (int col = 0; col < 26; col++) {
                if (map.map[row][col] != 0) {
                    SetRect(&map.TileRect[row][col], 24 + col * 24, 28 + row * 24, 24 + col * 24 + 24, 28 + row * 24 + 24);
                    RECT intersection;
                    if (IntersectRect(&intersection, &nextColider, &map.TileRect[row][col])) {
                        return;
                    }
                }
            }
        }

        //eTank2
        eTank2.nowy -= up * speed;
        eTank2.nowy += down * speed;
        eTank2.nowx += right * speed;
        eTank2.nowx -= left * speed;
        SetRect(&eTank2.enemy2Colider, eTank2.nowx, eTank2.nowy, eTank2.nowx + 43, eTank2.nowy + 43);
    }
}


    float Enemy::GetNowX()
    {
        return nowx;
    }
    float Enemy::GetNowY()
    {
        return nowy;
    }

    static DWORD statetime = GetTickCount64();

    void Enemy::Update()
    {
        if (GetTickCount64() - statetime > 1000)
        {
            srand(time(NULL));
            eTank1.enemyState = rand() % (5 - 2 + 1) + 2;
            eTank2.enemyState= rand() % (5 - 2 + 1) + 2;
        }

            switch (eTank1.enemyState)
            {
            case start:
                enemyState = STATE::idle;
                eTank1.AniFlame = 0;
                break;
            case left:
                eTank1Move(1.f, 0, 0, 0);
                char Filename[256];
                for (int i = 0; i < 2; i++) {
                    sprintf_s(Filename, "./resource/Img/enemy/enemy1_left_%02d.png", i + 1);
                    eTank1.enemy1[i].Create(Filename, true, D3DCOLOR_XRGB(0, 128, 128));
                }
                eTank1.AniFlame = 0;
                eTank1.AniTime = GetTickCount64();
                break;
            case right:
                eTank1Move(0, 1.f, 0, 0);
                
                for (int i = 0; i < 2; i++) {
                    sprintf_s(Filename, "./resource/Img/enemy/enemy1_right_%02d.png", i + 1);
                    eTank1.enemy1[i].Create(Filename, true, D3DCOLOR_XRGB(0, 128, 128));
                }
                eTank1.AniFlame = 0;
                eTank1.AniTime = GetTickCount64();
                break;
            case up:
                eTank1Move(0, 0, 1.f, 0);
               
                for (int i = 0; i < 2; i++) {
                    sprintf_s(Filename, "./resource/Img/enemy/enemy1_up_%02d.png", i + 1);
                    eTank1.enemy1[i].Create(Filename, true, D3DCOLOR_XRGB(0, 128, 128));
                }
                eTank1.AniFlame = 0;
                eTank1.AniTime = GetTickCount64();
                break;
            case down:
                eTank1Move(0, 0, 0, 1.f);
               
                for (int i = 0; i < 2; i++) {
                    sprintf_s(Filename, "./resource/Img/enemy/enemy1_down_%02d.png", i + 1);
                    eTank1.enemy1[i].Create(Filename, true, D3DCOLOR_XRGB(0, 128, 128));
                }
                eTank1.AniFlame = 0;
                eTank1.AniTime = GetTickCount64();
                break;
            }

            switch (eTank2.enemyState)
            {
            case start:
                eTank2.enemyState = STATE::idle;
                eTank2.AniFlame = 0;
                break;
            case left:
                eTank2Move(1.f, 0, 0, 0);
                char Filename[256];
                for (int i = 0; i < 2; i++) {
                    sprintf_s(Filename, "./resource/Img/enemy/enemy2_left_%02d.png", i + 1);
                    eTank2.enemy2[i].Create(Filename, true, D3DCOLOR_XRGB(0, 128, 128));
                }
                eTank2.AniFlame = 0;
                eTank2.AniTime = GetTickCount64();
                break;

            case right:
                eTank2Move(0, 1.f, 0, 0);
                for (int i = 0; i < 2; i++) {
                    sprintf_s(Filename, "./resource/Img/enemy/enemy2_right_%02d.png", i + 1);
                    eTank2.enemy2[i].Create(Filename, true, D3DCOLOR_XRGB(0, 128, 128));
                }
                eTank2.AniFlame = 0;
                eTank2.AniTime = GetTickCount64();
                break;
            case up:
                eTank2Move(0, 0, 1.f, 0);
                for (int i = 0; i < 2; i++) {
                    sprintf_s(Filename, "./resource/Img/enemy/enemy2_up_%02d.png", i + 1);
                    eTank2.enemy2[i].Create(Filename, true, D3DCOLOR_XRGB(0, 128, 128));
                }
                eTank2.AniFlame = 0;
                eTank2.AniTime = GetTickCount64();
                break;
            case down:
                eTank2Move(0, 0, 0, 1.f);
                for (int i = 0; i < 2; i++) {
                    sprintf_s(Filename, "./resource/Img/enemy/enemy2_down_%02d.png", i + 1);
                    eTank2.enemy2[i].Create(Filename, true, D3DCOLOR_XRGB(0, 128, 128));
                }
                eTank2.AniFlame = 0;
                eTank2.AniTime = GetTickCount64();
                break;
            }
    }

    void Enemy::Draw()
    {
        if (!eTank1.isDead)
        {
            eTank1.enemy1[eTank1.AniFlame].Render(eTank1.nowx, eTank1.nowy, 0, 3, 3);
            if (Gmanager.m_Collision == true)
            {
                colider1.Render(eTank1.nowx, eTank1.nowy, 0, 1, 1);
            }
        }
        else
        {
            // ���� ��� ������ �õ��ϱ�
            if (respawnCount1 < MAX_SPAWN_COUNT)
            {
                // ������ ������ Ƚ���� ���� ��쿡�� ����
                static clock_t lastRespawnTime1 = clock();
                const int RESPAWN_INTERVAL1 = 3000; // 5��(�и��� ����)
                
               
                if (clock() - lastRespawnTime1 > RESPAWN_INTERVAL1)
                {
                    // ������ �ð��� �Ǹ� ��Ƴ��� ���·� �ʱ�ȭ
                    eTank1.nowx = 28;
                    eTank1.nowy = 32;
                    speed = 2.f;
                    eTank1.isDead = false;
                    SetRect(&eTank1.enemy1Colider, eTank1.nowx, eTank1.nowy, eTank1.nowx + 43, eTank1.nowy + 43);
                      respawnCount1++;
                    lastRespawnTime1 = clock();
                }
            }
        }
     
        if (!eTank2.isDead)
        {
            eTank2.enemy2[eTank2.AniFlame].Render(eTank2.nowx, eTank2.nowy, 0, 3, 3);
            if (Gmanager.m_Collision == true)
            {
                colider2.Render(eTank2.nowx, eTank2.nowy, 0, 1, 1);
            }
        }
        else
        {
            
            // eTank2�� �׾��ٸ� ������ ��Ŵ
            // ������ �ð��� �Ǹ� ��Ƴ��� ���·� �ʱ�ȭ
            if (respawnCount2 < MAX_SPAWN_COUNT)
            {
                static clock_t lastRespawnTime2 = clock();
                const int RESPAWN_INTERVAL2 = 3000; // 5��(�и��� ����)

                if (clock() - lastRespawnTime2 > RESPAWN_INTERVAL2)
                {
                    eTank2.nowx = 605;
                    eTank2.nowy = 32;
                    speed = 2.f;
                    eTank2.isDead = false;
                    SetRect(&eTank2.enemy2Colider, eTank2.nowx, eTank2.nowy, eTank2.nowx + 43, eTank2.nowy + 43);
                    respawnCount2++;
                    lastRespawnTime2 = clock();
                }
            }
        }
    }


    void Enemy::RemoveEnemy1() {
        // �� ��ũ �ݶ��̴� ����
        SetRect(&enemy1Colider, 0, 0, 0, 0);
    }
    void Enemy::RemoveEnemy2() {
        // �� ��ũ �ݶ��̴� ����
        SetRect(&enemy2Colider, 0, 0, 0, 0);
    }

   