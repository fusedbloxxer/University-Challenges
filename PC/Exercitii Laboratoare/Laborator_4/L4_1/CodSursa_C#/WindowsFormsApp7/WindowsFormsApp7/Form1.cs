using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApp7
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public int dif_rand(int[] List, ref int n, int max_val)
        {
            Random rnf = new Random();
            int c, ok;

            do
            {
                c = rnf.Next(1, max_val + 1);
                ok = 0;

                for (int i = 0; i < n; i++)
                    if (List[i] == c) { i = n; ok = 1; }
                        
            } while (ok == 1);

            List[n] = c;n++;

            return c;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = "";

            Random rnd = new Random();
            int n=0;
            string[] Text;//=new string[51];
            Text=richTextBox2.Text.Split('\n');
            int[] visited = new int[Text.Length];

            for (int i = 0; i < Text.Length; i++)
            {
                richTextBox1.Text = richTextBox1.Text + Text[i] + "\n";
                richTextBox1.Text = richTextBox1.Text + (float)(rnd.Next(1, 10) + (double)rnd.Next(0, 10) / 10) + "\n";
                richTextBox1.Text = richTextBox1.Text + (float)(rnd.Next(1, 10) + (double)rnd.Next(0, 10) / 10) + "\n";
                richTextBox1.Text = richTextBox1.Text + (float)(rnd.Next(1, 10) + (double)rnd.Next(0, 10) / 10) + "\n";
                richTextBox1.Text = richTextBox1.Text + dif_rand(visited,ref n,Text.Length) + "\n";
            }

            label4.Text = Text.Length.ToString();

            StreamWriter sw = new StreamWriter(@"date.in");
            sw.Write(richTextBox1.Text);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (richTextBox2.Text.Length == 0)
            { label3.Text = "Introduceti nume!"; label3.BackColor = Color.Red; button1.Enabled = false; button1.BackColor = Color.Red; }
            else
            { label3.Text = "Puteti genera!"; label3.BackColor = Color.Green; button1.Enabled = true; button1.BackColor = Color.Green; }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            label4.Text = "";
            richTextBox2.Text = System.IO.File.ReadAllText(@"names.txt");
        }
    }
}
