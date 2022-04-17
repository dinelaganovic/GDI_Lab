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
    public partial class Stranica2 : Form
    {
        public Stranica2()
        {
            InitializeComponent();
        }

        private void Stranica2_Paint(object sender, PaintEventArgs e)
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
