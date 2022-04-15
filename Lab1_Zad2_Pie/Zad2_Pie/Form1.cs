using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Zad2_Pie
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(textBox1.Text=="" || textBox2.Text == ""|| textBox3.Text == ""|| textBox4.Text == ""|| textBox5.Text == "")
            {
                MessageBox.Show("Unesite sve podatke!");
            }
            else
            {
                chart1.Titles.Add("Pie Chart");
                int a = Int16.Parse(textBox1.Text);
                int b = Int16.Parse(textBox2.Text);
                int c = Int16.Parse(textBox3.Text);
                int d = Int16.Parse(textBox4.Text);
                int f = Int16.Parse(textBox5.Text);
                chart1.Series["chart"].Points.AddXY("1", a);
                chart1.Series["chart"].Points.AddXY("2", b);
                chart1.Series["chart"].Points.AddXY("3", c);
                chart1.Series["chart"].Points.AddXY("4", d);
                chart1.Series["chart"].Points.AddXY("5", f);
            }
        }
    }
}
