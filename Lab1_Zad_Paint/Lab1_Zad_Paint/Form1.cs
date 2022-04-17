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

        private void button1_Click(object sender, EventArgs e)
        {
             Graphics g = this.CreateGraphics();
             Pen pn = new Pen(Color.Blue, 5);
             PointF point1 = new PointF(10, 10);
             PointF point2 = new PointF(150, 10);
             PointF point3 = new PointF(100, 75);
             PointF point4 = new PointF(50, 75);
             PointF[] curvePoints = { point1, point2, point3, point4 };
             g.DrawPolygon(pn, curvePoints);
             //patern u pravougaoniku
            System.Drawing.Drawing2D.HatchBrush hBrush1 = new System.Drawing.Drawing2D.HatchBrush(System.Drawing.Drawing2D.HatchStyle.DiagonalCross, Color.Black, Color.Red);
            g.FillRectangle(hBrush1, 20, 80, 160, 120);
            //Trapez sa tekstom unutra
            Point[] polyPoints = {
              new Point(10, 10),
               new Point(150, 10),
               new Point(100, 75),
              new Point(50, 75)};
            System.Drawing.Drawing2D.GraphicsPath path = new System.Drawing.Drawing2D.GraphicsPath();
            path.AddPolygon(polyPoints);
            // Construct a region based on the path.
            Region region = new Region(path);
            // Draw the outline of the region.
            Pen pen = Pens.Black;
            g.DrawPath(pen, path);
            // Set the clipping region of the Graphics object.
            g.SetClip(region, System.Drawing.Drawing2D.CombineMode.Replace);
            // Draw some clipped strings.
            FontFamily fontFamily = new FontFamily("Arial");
            Font font = new Font(
            fontFamily,
            36, FontStyle.Bold,
            GraphicsUnit.Pixel);
            SolidBrush solidBrush = new SolidBrush(Color.FromArgb(255, 255, 0, 0));
            g.DrawString(
            "A Clipping Region",
            font, solidBrush,
            new PointF(15, 25));
            g.DrawString(
            "A Clipping Region",
            font,
            solidBrush,
            new PointF(15, 68));

            //luk
            Pen pnnn = new Pen(Color.Black, 5);
            Rectangle recttt = new Rectangle(50, 50, 200, 100);
            g.DrawArc(pnnn, recttt, 12, 84);
        }
    }
}
