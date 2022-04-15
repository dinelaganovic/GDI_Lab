using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab1_Zad1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Graphics g = this.CreateGraphics();
            Pen p = new Pen(Color.White, 3);
            Rectangle r = new Rectangle(120, 50, 200, 30);
            g.DrawEllipse(p, r);
            Font f = new Font(FontFamily.GenericSerif, 14, FontStyle.Bold);
            Brush b = new SolidBrush(Color.Red);
            g.DrawString("START", f, b, 190, 55);
            p.EndCap = System.Drawing.Drawing2D.LineCap.ArrowAnchor;
            g.DrawLine(p, 220, 80, 220, 100);

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (text.Text == "")
            {
                MessageBox.Show("Ulaz mor da ima svoju vrednost");
            }
            else
            {
                Graphics g = this.CreateGraphics();
                Pen p = new Pen(Color.White, 3);
                Point[] po = { new Point(150, 100), new Point(300, 100), new Point(280, 130), new Point(170, 130) };
                g.DrawPolygon(p, po);
                String s = this.text.Text;
                Font f = new Font(FontFamily.GenericSerif, 14, FontStyle.Bold);
                Brush b = new SolidBrush(Color.Red);
                g.DrawString(s, f, b, 200, 105);
                p.EndCap = System.Drawing.Drawing2D.LineCap.ArrowAnchor;
                g.DrawLine(p, 220, 130, 220, 150);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Graphics g = this.CreateGraphics();
            Pen p = new Pen(Color.White, 3);
            Rectangle r = new Rectangle(120, 150, 200, 30);
            g.DrawRectangle(p, r);
            Font f = new Font(FontFamily.GenericSerif, 14, FontStyle.Bold);
            Brush b = new SolidBrush(Color.Red);
            String s = "Neka petlja";
            g.DrawString(s, f, b, 180, 155);
            p.EndCap = System.Drawing.Drawing2D.LineCap.ArrowAnchor;
            g.DrawLine(p, 220, 180, 220, 200);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (text1.Text == "")
            {
                MessageBox.Show("Izlaz mora da ima svoju vrednost");
            }
            else
            {
                Graphics g = this.CreateGraphics();
                Pen p = new Pen(Color.White, 3);
                Point[] po = { new Point(280, 200), new Point(170, 200), new Point(150, 230), new Point(300, 230) };
                g.DrawPolygon(p, po);
                String s = this.text1.Text;
                Font f = new Font(FontFamily.GenericSerif, 14, FontStyle.Bold);
                Brush b = new SolidBrush(Color.Red);
                g.DrawString(s, f, b, 200, 205);
                p.EndCap = System.Drawing.Drawing2D.LineCap.ArrowAnchor;
                g.DrawLine(p, 220, 230, 220, 250);
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Graphics g = this.CreateGraphics();
            Pen p = new Pen(Color.White, 3);
            Rectangle r = new Rectangle(120, 250, 200, 30);
            g.DrawEllipse(p, r);
            Font f = new Font(FontFamily.GenericSerif, 14, FontStyle.Bold);
            Brush b = new SolidBrush(Color.Red);
            g.DrawString("KRAJ", f, b, 190, 255);
        }
    }
}
