using System;

namespace _001
{
    class Program
    {
        static int[] AB = { 0, 0 };
        static int[] Map = new int[105];
        static int[] Map_copy = new int[105];
        static string[] Name = new string[2];
        public static void Win()
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("                                          ◆                      ");
            Console.WriteLine("                    ■                  ◆               ■        ■");
            Console.WriteLine("      ■■■■  ■  ■                ◆■         ■    ■        ■");
            Console.WriteLine("      ■    ■  ■  ■              ◆  ■         ■    ■        ■");
            Console.WriteLine("      ■    ■ ■■■■■■       ■■■■■■■   ■    ■        ■");
            Console.WriteLine("      ■■■■ ■   ■                ●■●       ■    ■        ■");
            Console.WriteLine("      ■    ■      ■               ● ■ ●      ■    ■        ■");
            Console.WriteLine("      ■    ■ ■■■■■■         ●  ■  ●     ■    ■        ■");
            Console.WriteLine("      ■■■■      ■             ●   ■   ■    ■    ■        ■");
            Console.WriteLine("      ■    ■      ■            ■    ■         ■    ■        ■");
            Console.WriteLine("      ■    ■      ■                  ■               ■        ■ ");
            Console.WriteLine("     ■     ■      ■                  ■           ●  ■          ");
            Console.WriteLine("    ■    ■■ ■■■■■■             ■              ●         ●");
            Console.ResetColor();
        }//获胜打印
        static void swap()
        {
            int m = AB[0];
            AB[0] = AB[1];
            AB[1] = m;
        }//交换
        static bool voctry()
        {
            if(AB[0] >= 99)
            {
                Console.WriteLine("玩家 {0} 获胜！！！！", Name[0]);
                Win();
                return true;
            }
            if(AB[1] >= 99)
            {
                Console.WriteLine("玩家 {0} 获胜！！！！", Name[1]);
                Win();
                return true;
            }
            return false;
        }//判断胜利
        static void mune()
        {
            Console.ForegroundColor = ConsoleColor.Blue;
            Console.WriteLine("**************");
            Console.ForegroundColor = ConsoleColor.DarkCyan;
            Console.WriteLine("**************");
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("****飞行棋****");
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("**************");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("**************");
            Console.ForegroundColor = ConsoleColor.White;


        }//菜单显示
        static void get_name()
        {
            do
            {
                Console.WriteLine("请输入玩家 A 的姓名：");
                Name[0] = Console.ReadLine();
                if (string.IsNullOrEmpty(Name[0]))
                {
                    Console.WriteLine("玩家 A 姓名不能为空！！");
                }
            } while (string.IsNullOrEmpty(Name[0]));
            do
            {
                if (Name[0] == Name[1])
                {
                    Console.WriteLine("玩家 A ，玩家 B 姓名不能重复！请重新输入！");
                }
                else
                {
                    Console.WriteLine("请输入玩家 B 的姓名：");
                }
                Name[1] = Console.ReadLine();
                if (string.IsNullOrEmpty(Name[1]))
                {
                    Console.WriteLine("玩家 B 姓名不能为空！！");
                }
            } while (string.IsNullOrEmpty(Name[1]) || Name[0] == Name[1]);
        }//获取玩家姓名
        static void make_map()
        {
            int[] boom = { 10, 23, 56, 84, 21 };
            int[] judge = { 5, 16, 36, 87, 66, 73 };
            int[] timeturn = { 3, 12, 29, 34, 47, 58, 71, 86 };
            int[] puase = { 32, 55, 46, 98, 22, 49 };
            Console.ForegroundColor = ConsoleColor.Red;
            Console.Write("\n88 : 地雷    ");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.Write("▼ ：幸运转盘    ");
            Console.ForegroundColor = ConsoleColor.Blue;
            Console.Write("卐 ：时空隧道    ");
            Console.ForegroundColor = ConsoleColor.Magenta;
            Console.WriteLine("丷 : 暂停\n");
            {
                for (int i = 0; i < Map.Length; i++)
                {
                    Map[i] = 0;
                }
                for (int i = 0; i < boom.Length; i++)
                {
                    Map[boom[i]] = 1;
                }
                for (int i = 0; i < judge.Length; i++)
                {
                    Map[judge[i]] = 2;
                }
                for (int i = 0; i < timeturn.Length; i++)
                {
                    Map[timeturn[i]] = 3;
                }
                for (int i = 0; i < puase.Length; i++)
                {
                    Map[puase[i]] = 4;
                }
            }//给地图中遍历特殊点1，2，3，4
            for(int i = 0; i < 100; i++)
            {
                Map_copy[i] = Map[i];
            }
            //输出地图
        }//初始化地图
        static void print_map()
        {
            for (int i = 0; i < 30; i++)
            {
                symbol(Map[i]);
            }
            Console.WriteLine();
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 58; j++)
                {
                    Console.Write(" ");
                }
                symbol(Map[i + 30]);
                Console.WriteLine();
            }
            for (int i = 64; i >= 35; i--)
            {
                symbol(Map[i]);
            }
            Console.WriteLine();
            for (int i = 0; i < 5; i++)
            {
                symbol(Map[i + 65]);
                Console.WriteLine();
            }
            for (int i = 70; i < 100; i++)
            {
                symbol(Map[i]);
            }
            Console.WriteLine();
        }//输出地图
        static void symbol(int s)
        {
            switch(s)
            {
                case 0:
                    Console.ForegroundColor = ConsoleColor.Yellow;
                    Console.Write("□");
                    Console.ForegroundColor = ConsoleColor.White; break;
                case 1:
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.Write("88"); 
                    Console.ForegroundColor = ConsoleColor.White; break;
                case 2:
                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.Write("▼");
                    Console.ForegroundColor = ConsoleColor.White; break;
                case 3:
                    Console.ForegroundColor = ConsoleColor.Blue;
                    Console.Write("卐");
                    Console.ForegroundColor = ConsoleColor.White; break;
                case 4:
                    Console.ForegroundColor = ConsoleColor.Magenta;
                    Console.Write("丷");
                    Console.ForegroundColor = ConsoleColor.White; break; 
                case 5:
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.Write("-A");break; 
                case 6:
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.Write("-B");break;
                case 7:
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.Write("<>"); break;
            }
        }//控制地图的花色
        static void judge_game(int x,int s,int move)
        {
            switch (Map[x])
            {
                case 1:
                    Console.WriteLine("踩到了雷！后退六步！！");
                    if(AB[s] <= 6)
                    {
                        AB[s] = 0;
                    }
                    else
                    {
                        AB[s] -= 6;
                    }
                    break;
                case 2:
                    bool falg = false;
                    do
                    {
                        Console.WriteLine("请选择\n1: 与对方交换位置\n2:让对方后退6步");
                        try
                        {
                            switch (int.Parse(Console.ReadLine()))
                            {
                                case 1: 
                                    swap();
                                    Console.WriteLine("A与B 已交换位置"); falg = false; 
                                    break;
                                case 2:
                                    if(s == 0)
                                    {
                                        if (AB[1] <= 6)
                                        {
                                            AB[1] = 0;
                                        }
                                        else
                                        {
                                            AB[1] -= 6;
                                        }
                                    }
                                    else
                                    {
                                        if (AB[0] <= 6)
                                        {
                                            AB[0] = 0;
                                        }
                                        else
                                        {
                                            AB[0] -= 6;
                                        }
                                    }
                                    Console.WriteLine("让对方已经退后6步");
                                    falg = false;break;
                                default:
                                    Console.WriteLine("请输入正确的数字！");falg = true;
                                    break;
                            }
                        }
                        catch
                        {
                            falg = true;
                        }
                    } while (falg);break;
                case 3:
                    Console.WriteLine("进入了时空隧道，前进五步");
                    AB[s] += 5;
                    break;
                case 4:
                    Console.WriteLine("踩到了暂停按钮，什么都没有发生");
                    if(AB[s] <= move)
                    {
                        AB[s] = 0;
                    }
                    else
                    {
                        AB[s] -= move;
                    }
                    break;
                default:
                    Console.WriteLine("什么都没有发生————————————");
                    break;
            }
        }//判断移动后的事件
        static void game_1()
        {
            int m = AB[0];
            Random x = new Random();
            Console.WriteLine("请玩家 A {0}按任意键掷 1 ~ 6 的色子",Name[0]);
            Console.ReadKey();
            int move = x.Next(1, 6);
            Console.WriteLine("移动了{0}步",move);
            AB[0] += move;
            judge_game(AB[0], 0, move);
            if(m != AB[0])
            {
                Map[m] = Map_copy[m];
            }
            Console.WriteLine("按任意键继续————>");
            Console.ReadKey();
        }//玩家A移动
        static void game_2()
        {
            int m = AB[1];
            Random x = new Random();
            Console.WriteLine("请玩家 B {0}按任意键掷 1 ~ 6 的色子", Name[1]);
            Console.ReadKey();
            int move = x.Next(1, 6);
            Console.WriteLine("移动了{0}步", move);
            AB[1] += move;
            judge_game(AB[1], 1, move);
            if (m != AB[1])
            {
                Map[m] = Map_copy[m];
            }
            Console.WriteLine("按任意键继续————>");
            Console.ReadKey();
        }//玩家B移动
        static void AB_locate()
        {
            if (AB[0] == AB[1])
            {
                Map[AB[0]] = 7;
            }
            else
            {
                Map[AB[0]] = 5;
                Map[AB[1]] = 6;
            }
        }//A与B的坐标位置换成图像
        static void Main(string[] args)
        {
            int i = 0;
            mune();
            make_map();
            get_name();
            Console.Clear();
            while(AB[0] < 100 && AB[1] < 100)
            {
                Console.Clear();
                Console.WriteLine("\n玩家 A :{0}   玩家 B :{1}", Name[0], Name[1]);
                AB_locate();
                print_map();
                if (i == 0)
                {
                    game_1();
                    i++;
                }
                else
                {
                    game_2();
                    i--;
                }
                if (voctry())
                {
                    break;
                }
            }
            Console.Read();
        }
    }
}
