using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;

namespace risk_calculator
{
    public partial class Form1 : Form
    {
        int RiskIndex = 1;
        int Age;
        int ProjectionAge;
        int AgeIndicator;
        int AgeMenarche;
        int AgeBirth;
        int HadBio;
        int NoBio;
        int Hyp;
        double RHyp;
        int FirstDegRel;
        int Race;

        public Form1()
        {
            InitializeComponent();
      

        }
      
        private void AgeBox_TextChanged(object sender, EventArgs e)
        {
            Age = int.Parse(AgeBox.Text);
            if (Age > 50)
                AgeIndicator = 1;
            else
                AgeIndicator = 0;
            ProjectionAge = Age + 5;
        }


        private void MenBox_TextChanged(object sender, EventArgs e)
        {
            int menarche = int.Parse(MenBox.Text);
            if (menarche > Age)
                MessageBox.Show("Wrong data");

            if (menarche >= 14)
                AgeMenarche = 0;
            else
                if (menarche >= 12)
                AgeMenarche = 1;
            else
                AgeMenarche = 2;
            //Console.WriteLine("Menarche Age is:");
            //Console.WriteLine(AgeMenarche);
        }

        private void BirthBox_TextChanged(object sender, EventArgs e)
        {
            int birth = int.Parse(BirthBox.Text);
            if (birth > Age)
                MessageBox.Show("Wrong data");
            if (birth <= 20 || birth == 99)
                AgeBirth = 0;
            else if (birth < 25)
                AgeBirth = 1;
            else if (birth < 30)
                AgeBirth = 2;
            else if (birth < 55)
                AgeBirth = 3;
           // Console.WriteLine(AgeBirth);
        }

        private void NoBioBox_TextChanged(object sender, EventArgs e)
        {
            int bio = int.Parse(NoBioBox.Text);
            if (bio == 0 || bio == 99)
                NoBio = 0;
            if (bio == 1)
                NoBio = 1;
            if (bio >= 2 && bio <= 30)
                NoBio = 2;

            if (NoBioButton.Checked == true && NoBio != 0)
                MessageBox.Show("Wrong data");
            if (YesBioButton.Checked == true && NoBio == 0)
                MessageBox.Show("Wrong data");

            //Console.WriteLine(NoBio);
        }

        private void FirstDegRelBox_TextChanged(object sender, EventArgs e)
        {
            int rel = int.Parse(FirstDegRelBox.Text);
            if (rel == 0 || rel == 99)
                FirstDegRel = 0;
            if (rel == 1)
                FirstDegRel = 1;
            if (rel >= 2 && rel <= 31)
                FirstDegRel = 2;

            //Console.WriteLine(FirstDegRel);
        }


        private void RaceBox_TextChanged(object sender, EventArgs e)
        {
            Race = int.Parse(RaceBox.Text);
            //Console.WriteLine(Race);
        }

        private void YesBioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (YesBioButton.Checked == true)
            {
                HadBio = 1;
            }
            //Console.WriteLine(HadBio);
        }

        private void NoBioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (NoBioButton.Checked == true)
            {
                HadBio = 0;
            }
            //Console.WriteLine(HadBio);
        }

        private void UnknownBioButton_CheckedChanged(object sender, EventArgs e)
        {
           
            if (UnknownBioButton.Checked == true)
            {
                HadBio = 99;
            }

            //Console.WriteLine(HadBio);
        }

        private void YesHyp_CheckedChanged(object sender, EventArgs e)
        {
            if (YesHyp.Checked == true)
            {
                Hyp = 1;
                RHyp = 1.82;
            }
            //Console.WriteLine(Hyp);
        }

        private void NoHyp_CheckedChanged(object sender, EventArgs e)
        {
            if (NoHyp.Checked == true)
            {
                Hyp = 0;
                if (HadBio == 1)
                    RHyp = 0.93;
                if (HadBio == 0)
                    RHyp = 1;
            }
            //Console.WriteLine(Hyp);
        }

        private void UnknownHyp_CheckedChanged(object sender, EventArgs e)
        {
            if (UnknownHyp.Checked == true)
            {
                Hyp = 99;
            }
            //Console.WriteLine(Hyp);
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            Console.WriteLine("Rezultate:");
            Console.WriteLine("Age:");
            Console.WriteLine(Age);
            Console.WriteLine("Projection age:");
            Console.WriteLine(ProjectionAge);
            Console.WriteLine("Age indicator:");
            Console.WriteLine(AgeIndicator);
            Console.WriteLine("Age menarche:");
            Console.WriteLine(AgeMenarche);
            Console.WriteLine("Age birth:");
            Console.WriteLine(AgeBirth);
            Console.WriteLine("Had Biopsy:");
            Console.WriteLine(HadBio);
            Console.WriteLine("Number of biopsies:");
            Console.WriteLine(NoBio);
            Console.WriteLine("Hyperplasia:");
            Console.WriteLine(Hyp);
            Console.WriteLine("RHyperplasia:");
            Console.WriteLine(RHyp);
            Console.WriteLine("First degree relatives:");
            Console.WriteLine(FirstDegRel);
            Console.WriteLine("Race:");
            Console.WriteLine(Race);

            StreamWriter f = new StreamWriter("C:\\Users\\andreea.cotiga\\Desktop\\Gail\\indici.txt");
            //string path1 = Path.GetFullPath("Gail\\indici.txt");
            //StreamWriter f = new StreamWriter(path1);
            f.WriteLine(RiskIndex);
            f.WriteLine(Age); 
            f.WriteLine(ProjectionAge);
            f.WriteLine(AgeIndicator);
            f.WriteLine(NoBio);
            f.WriteLine(AgeMenarche);
            f.WriteLine(AgeBirth);
            f.WriteLine(HadBio);
            f.WriteLine(FirstDegRel);
            f.WriteLine(Hyp);
            f.WriteLine(RHyp);
            f.WriteLine(Race);

            f.Close();

            Directory.SetCurrentDirectory(@"C:\\Users\\andreea.cotiga\\Desktop\\Gail");
            //string path2 = Path.GetFullPath("Desktop\\Gail");
            //Directory.SetCurrentDirectory(@path2);

            Process myProcess = new Process();
            myProcess.StartInfo.FileName = @"C:\\Users\\andreea.cotiga\\Desktop\\Gail\\Proiect POO.exe"; // Note the absolute path
            //string path3 = Path.GetFullPath("Desktop\\Gail\\Proiect POO.exe");
            //myProcess.StartInfo.FileName = @path3;
            myProcess.Start();

        }


        private void button2_Click(object sender, EventArgs e)
        {
            StreamReader fin = new StreamReader("C:\\Users\\andreea.cotiga\\Desktop\\Gail\\risc.txt");
            //string path4 = Path.GetFullPath("Desktop\\Gail\\risc.txt");
            //StreamReader fin = new StreamReader(path4);
            string risc = fin.ReadLine();
            fin.Close();

            MessageBox.Show("Riscul pe urmatorii 5 ani este de " + risc+"%");
        }  
    }
}
