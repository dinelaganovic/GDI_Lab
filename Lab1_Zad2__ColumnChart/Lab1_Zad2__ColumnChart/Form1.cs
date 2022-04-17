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

namespace Lab1_Zad2__ColumnChart
{
    public partial class Chart : Form
    {
        private void button1_Click(object sender, EventArgs e)
        {
            int a = Int16.Parse(textBox1.Text);
            int b = Int16.Parse(textBox2.Text);
            int c = Int16.Parse(textBox3.Text);
            int d = Int16.Parse(textBox4.Text);
            int f = Int16.Parse(textBox5.Text);
            Graphics g = CreateGraphics();
            Rectangle rect = new Rectangle(110, 60, 80, a);
            SolidBrush blueBrush = new SolidBrush(Color.Blue);
            g.FillRectangle(blueBrush, rect);
            Rectangle rect2 = new Rectangle(210, 60, 80, b);
            SolidBrush blueBrush2 = new SolidBrush(Color.Black);
            g.FillRectangle(blueBrush2, rect2);
            Rectangle rect3 = new Rectangle(310, 60, 80, c);
            SolidBrush blueBrush3 = new SolidBrush(Color.White);
            g.FillRectangle(blueBrush3, rect3);
            Rectangle rect4 = new Rectangle(410, 60, 80, d);
            SolidBrush blueBrush4 = new SolidBrush(Color.Pink);
            g.FillRectangle(blueBrush4, rect4);
            Rectangle rect5 = new Rectangle(510, 60, 80, f);
            SolidBrush blueBrush5 = new SolidBrush(Color.Yellow);
            g.FillRectangle(blueBrush5, rect5);
        }

        public Chart()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Pen pn = new Pen(Color.Black,7);
            Point pt1 = new Point(90, 50);
            Point pt2 = new Point(620, 50);
            g.DrawLine(pn, pt1, pt2);
        }

    }
}
