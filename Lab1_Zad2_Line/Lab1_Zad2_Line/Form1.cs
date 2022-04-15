using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab1_Zad2_Line
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private Point startPoint = new Point(50, 217);
        private Point endPoint = new Point(50, 217);
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Font vertFont = new Font("Verdana", 10, FontStyle.Bold);
            Font horzFont = new Font("Verdana", 10, FontStyle.Bold);
            SolidBrush vertBrush = new SolidBrush(Color.Black);
            SolidBrush horzBrush = new SolidBrush(Color.Blue);
            Pen blackPen = new Pen(Color.Black);
            Pen bluePen = new Pen(Color.Blue);

            // Drawing a vertical and a horizontal line
            g.DrawLine(blackPen, 50, 220, 50, 25);
            g.DrawLine(bluePen, 50, 220, 250, 220);

            // x-axis drawing
            g.DrawString("0", horzFont, horzBrush, 30, 220);
            g.DrawString("1", horzFont, horzBrush, 50, 220);
            g.DrawString("2", horzFont, horzBrush, 70, 220);
            g.DrawString("3", horzFont, horzBrush, 90, 220);
            g.DrawString("4", horzFont, horzBrush, 110, 220);
            g.DrawString("5", horzFont, horzBrush, 130, 220);
            g.DrawString("6", horzFont, horzBrush, 150, 220);
            g.DrawString("7", horzFont, horzBrush, 170, 220);
            g.DrawString("8", horzFont, horzBrush, 190, 220);
            g.DrawString("9", horzFont, horzBrush, 210, 220);
            g.DrawString("10", horzFont, horzBrush, 230, 220);

            //Draw vertical strings
            StringFormat vertStrFormat = new StringFormat();
            vertStrFormat.FormatFlags = StringFormatFlags.DirectionVertical;
            g.DrawString("-", horzFont, horzBrush, 50, 212, vertStrFormat);
            g.DrawString("-", horzFont, horzBrush, 70, 212, vertStrFormat);
            g.DrawString("-", horzFont, horzBrush, 90, 212, vertStrFormat);
            g.DrawString("-", horzFont, horzBrush, 110, 212, vertStrFormat);
            g.DrawString("-", horzFont, horzBrush, 130, 212, vertStrFormat);
            g.DrawString("-", horzFont, horzBrush, 150, 212, vertStrFormat);
            g.DrawString("-", horzFont, horzBrush, 170, 212, vertStrFormat);
            g.DrawString("-", horzFont, horzBrush, 190, 212, vertStrFormat);
            g.DrawString("-", horzFont, horzBrush, 210, 212, vertStrFormat);
            g.DrawString("-", horzFont, horzBrush, 230, 212, vertStrFormat);

            // y-axis drawing
            g.DrawString("100 -", vertFont, vertBrush, 20, 20);
            g.DrawString("90 -", vertFont, vertBrush, 25, 40);
            g.DrawString("80 -", vertFont, vertBrush, 25, 60);
            g.DrawString("70 -", vertFont, vertBrush, 25, 80);
            g.DrawString("60 -", vertFont, vertBrush, 25, 100);
            g.DrawString("50 -", vertFont, vertBrush, 25, 120);
            g.DrawString("40 -", vertFont, vertBrush, 25, 140);
            g.DrawString("30 -", vertFont, vertBrush, 25, 160);
            g.DrawString("20 -", vertFont, vertBrush, 25, 180);
            g.DrawString("10 -", vertFont, vertBrush, 25, 200);

            // Dispose of objects
            vertFont.Dispose();
            horzFont.Dispose();
            vertBrush.Dispose();
            horzBrush.Dispose();
            blackPen.Dispose();
            bluePen.Dispose();
        }


        private void button1_Click(object sender, EventArgs e)
        {
            startPoint.X = 50;
            startPoint.Y = 217;
            endPoint.X = 50;
            endPoint.Y = 217;
            this.Invalidate(this.ClientRectangle);
        }


        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
              Graphics g1 = this.CreateGraphics();
               // Create two pens
                Pen linePen = new Pen(Color.Green, 1);
                Pen ellipsePen = new Pen(Color.Red, 1);
                startPoint = endPoint;
                endPoint = new Point(e.X, e.Y);
                // Draw the line from the current point
                // to the new point
                g1.DrawLine(linePen, startPoint, endPoint);
                // If rectangle check box is checked,
                // draw a rectangle to represent the point
                if (checkBox1.Checked)
                {
                    g1.DrawRectangle(ellipsePen, e.X - 2, e.Y - 2, 4, 4);
                }
                // Draw a circle to represent the point
                else
                {
                    g1.DrawEllipse(ellipsePen, e.X - 2, e.Y - 2, 4, 4);
                }
                //Dispose of objects
                linePen.Dispose();
                ellipsePen.Dispose();
                g1.Dispose();
            }
            }
    }
}
