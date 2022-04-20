using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab1_20042022
{
    public partial class Temperature : Form
    {
        public Temperature()
        {
            InitializeComponent();
        }

        private void Temperature_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Rectangle rect = new Rectangle(100, 50, 500, 700);
            LinearGradientBrush lBrush = new LinearGradientBrush(rect,
            Color.White, Color.Gray, LinearGradientMode.BackwardDiagonal);
            g.FillRectangle(lBrush, rect);
            Rectangle rect2 = new Rectangle(150, 100, 400, 600);
            LinearGradientBrush lBrush1 = new LinearGradientBrush(rect,
            Color.DarkGray, Color.White, LinearGradientMode.BackwardDiagonal);
            g.FillRectangle(lBrush1, rect2);
            //Tekst
            Font fnt = new Font("Times New Roman", 25);
            g.DrawString(" C°", fnt, new SolidBrush(Color.Red), 200, 630);
            Font fnt1 = new Font("Times New Roman", 25);
            g.DrawString(" F°", fnt1, new SolidBrush(Color.Red), 460, 630);

            //krug
            SolidBrush brush = new SolidBrush(Color.Red);
            Rectangle rect3 = new Rectangle(330, 630, 50, 50);
            Pen pn = new Pen(Color.Black, 3);
            Rectangle rec = new Rectangle(330, 630, 51, 51);
            g.DrawEllipse(pn, rec);
            g.FillEllipse(brush, rect3);

            //Skala
            SolidBrush bru = new SolidBrush(Color.LightGray);
            Rectangle rect4 = new Rectangle(333, 160, 44, 480);
            Pen pnnn = new Pen(Color.Black, 2);
            Rectangle reccc = new Rectangle(333, 160, 45, 480);
            g.DrawRectangle(pnnn, reccc);
            g.FillRectangle(bru, rect4);

            /// podeoci
            Font fnt2 = new Font("Times New Roman", 20);

            SolidBrush bru2 = new SolidBrush(Color.Blue);
            Rectangle podeok = new Rectangle(300, 240, 30, 3);
            g.FillRectangle(bru2, podeok);
            g.DrawString(" 40°", fnt2, new SolidBrush(Color.Black), 250, 220);
            g.DrawString(" 100°", fnt2, new SolidBrush(Color.Black), 400, 250);
            Rectangle podeok2 = new Rectangle(300, 320, 30, 3);
            g.FillRectangle(bru2, podeok2);
            g.DrawString(" 30°", fnt2, new SolidBrush(Color.Black), 250, 300);
            g.DrawString(" 80°", fnt2, new SolidBrush(Color.Black), 400, 320);
            Rectangle podeok3 = new Rectangle(300, 390, 30, 3);
            g.FillRectangle(bru2, podeok3);
            g.DrawString(" 20°", fnt2, new SolidBrush(Color.Black), 250, 380);
            g.DrawString(" 60°", fnt2, new SolidBrush(Color.Black), 400, 400);
            Rectangle podeok4 = new Rectangle(300, 450, 30, 3);
            g.FillRectangle(bru2, podeok4);
            g.DrawString(" 10°", fnt2, new SolidBrush(Color.Black), 250, 430);
            g.DrawString(" 40°", fnt2, new SolidBrush(Color.Black), 400, 460);
            Rectangle podeok5 = new Rectangle(300, 520, 30, 3);
            g.FillRectangle(bru2, podeok5);
            g.DrawString(" 0°", fnt2, new SolidBrush(Color.Black), 250, 500);
            g.DrawString(" 20°", fnt2, new SolidBrush(Color.Black), 400, 530);
            Rectangle podeok6 = new Rectangle(300, 580, 30, 3);
            g.FillRectangle(bru2, podeok6);
            g.DrawString(" -10°", fnt2, new SolidBrush(Color.Black), 250, 560);
            g.DrawString(" 0°", fnt2, new SolidBrush(Color.Black), 400, 590);
            Rectangle podeok7 = new Rectangle(300, 630, 30, 3);
            g.FillRectangle(bru2, podeok7);
            g.DrawString(" -20°", fnt2, new SolidBrush(Color.Black), 250, 610);
            g.TranslateTransform(80, 20);
            g.FillRectangle(bru2, podeok);
            g.FillRectangle(bru2, podeok2);
            g.FillRectangle(bru2, podeok3);
            g.FillRectangle(bru2, podeok4);
            g.FillRectangle(bru2, podeok5);
            g.FillRectangle(bru2, podeok6);
            //mali podeoci
            for (int j = 0; j <2; j ++)
            {
                SolidBrush br = new SolidBrush(Color.Green);
                for (int i = 0; i < 460; i += 14)
                {
                    
                    Rectangle podeokm = new Rectangle(230, 160 + i, 20, 2);
                    g.FillRectangle(br, podeokm);
                }
                g.TranslateTransform(72, 0);
               
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int temp;
            Int32.TryParse(textBox1.Text, out temp);
            Graphics g = CreateGraphics();
            if (textBox1.Text == "")
            {
                MessageBox.Show("Unesite temperaturu");
            }
            else
            {
                if (temp > 15)
                {
                    Pen pen = new Pen(Color.Red, 42);
                    Point pt1 = new Point(355, 260);
                    Point pt2 = new Point(355, 643);
                    g.DrawLine(pen, pt1, pt2);
                    Graphics g1 = panel1.CreateGraphics();
                    Bitmap bitmap1 = new Bitmap(Properties.Resources.Sun);
                    g1.DrawImage(bitmap1, 100, 20,100, 100);
                }
                else if (temp > 0 && temp < 15)
                {
                    Pen pen = new Pen(Color.Red, 42);
                    Pen pen2 = new Pen(Color.Black, 3);
                    Point pt1 = new Point(355,420);
                    Point pt2 = new Point(355, 643);
                    g.DrawLine(pen, pt1, pt2);
                    Graphics g1 = panel2.CreateGraphics();
                    Pen pn = new Pen(Color.Red, 5);
                    Rectangle rect = new Rectangle(10, 50, 50, 50);
                    g1.DrawArc(pen2, rect, 60, 180);
                    Point point1 = new Point(45, 98);
                    Point point2 = new Point(120, 98);
                    Point[] Points = { point1, point2};
                    g1.DrawCurve(pen2, Points);
                    Rectangle rect3 = new Rectangle(98, 50, 50, 50);
                    g1.DrawArc(pen2, rect3, -95, 200);
                    Rectangle rect5 = new Rectangle(15, 40, 50, 50);
                    g1.DrawArc(pen2, rect5, -180, 140);
                    Rectangle rect6 = new Rectangle(60, 20, 60, 60);
                    g1.DrawArc(pen2, rect6, -180, 190);
                }
                else if (temp <= 0)
                {
                    SolidBrush bru = new SolidBrush(Color.Red);
                    Rectangle rect4 = new Rectangle(333, 550, 43, 95);
                    g.FillRectangle(bru, rect4);
                    Graphics g1 = panel3.CreateGraphics();

                    float[] dashValues = { 5, 2, 5, 2 };
                    Pen blackPen = new Pen(Color.Black, 5);
                    blackPen.DashPattern = dashValues;
                    g1.DrawLine(blackPen, new Point(25, 5), new Point(0, 100));
                    g1.DrawLine(blackPen, new Point(45, 5), new Point(20, 100));
                    g1.DrawLine(blackPen, new Point(75, 5), new Point(50, 100));
                    g1.DrawLine(blackPen, new Point(95, 5), new Point(70, 100));
                    g1.DrawLine(blackPen, new Point(115, 5), new Point(90, 100));
                  
                }

            }
        }
    }
}
