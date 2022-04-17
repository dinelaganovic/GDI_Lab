using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab1_Zad_Paint
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            //ColumnChart sa translacijom
            Graphics g = e.Graphics;
            Pen pn = new Pen(Color.Blue, 5);
            Point pt1 = new Point(5, 300);
            Point pt2 = new Point(345, 300);
            g.DrawLine(pn, pt1, pt2);

            Rectangle rect = new Rectangle(10, 200, 40, 100);
            System.Drawing.Drawing2D.LinearGradientBrush lBrush = new System.Drawing.Drawing2D.LinearGradientBrush(rect,
Color.Red, Color.Red, System.Drawing.Drawing2D.LinearGradientMode.BackwardDiagonal);
            g.FillRectangle(lBrush, rect);

            Rectangle rect2 = new Rectangle(10, 210, 40, 90);
            System.Drawing.Drawing2D.LinearGradientBrush lBrush1 = new System.Drawing.Drawing2D.LinearGradientBrush(rect,
 Color.Blue, Color.Blue, System.Drawing.Drawing2D.LinearGradientMode.BackwardDiagonal);
            g.TranslateTransform(70, 0);
            g.FillRectangle(lBrush1, rect2);



            Rectangle rect1 = new Rectangle(50, 220, 40, 80);
            System.Drawing.Drawing2D.LinearGradientBrush lBrush2 = new System.Drawing.Drawing2D.LinearGradientBrush(rect,
Color.Pink, Color.Pink, System.Drawing.Drawing2D.LinearGradientMode.BackwardDiagonal);
            g.TranslateTransform(30, 0);
            g.FillRectangle(lBrush2, rect1);

            Rectangle rect3 = new Rectangle(50, 140, 40, 160);
            System.Drawing.Drawing2D.LinearGradientBrush lBrush3 = new System.Drawing.Drawing2D.LinearGradientBrush(rect,
Color.CadetBlue, Color.CadetBlue, System.Drawing.Drawing2D.LinearGradientMode.BackwardDiagonal);
            g.TranslateTransform(70, 0);
            g.FillRectangle(lBrush3, rect3);

            Rectangle rect4 = new Rectangle(50, 130, 40, 170);
            System.Drawing.Drawing2D.LinearGradientBrush lBrush4 = new System.Drawing.Drawing2D.LinearGradientBrush(rect,
Color.Green, Color.Green, System.Drawing.Drawing2D.LinearGradientMode.BackwardDiagonal);
            g.TranslateTransform(70, 0);
            g.FillRectangle(lBrush4, rect4);

          

        }

        private void stranica2ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Stranica2 str = new Stranica2();
            str.Show();
        }
    }
}
