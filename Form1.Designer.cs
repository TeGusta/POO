using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace risk_calculator
{
    partial class Form1
    {
        
        private System.ComponentModel.IContainer components = null;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

       
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.AgeBox = new System.Windows.Forms.TextBox();
            this.MenBox = new System.Windows.Forms.TextBox();
            this.NoBioBox = new System.Windows.Forms.TextBox();
            this.RaceBox = new System.Windows.Forms.TextBox();
            this.BirthBox = new System.Windows.Forms.TextBox();
            this.FirstDegRelBox = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.YesBioButton = new System.Windows.Forms.RadioButton();
            this.NoBioButton = new System.Windows.Forms.RadioButton();
            this.UnknownBioButton = new System.Windows.Forms.RadioButton();
            this.UnknownHyp = new System.Windows.Forms.RadioButton();
            this.NoHyp = new System.Windows.Forms.RadioButton();
            this.YesHyp = new System.Windows.Forms.RadioButton();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.label2 = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.groupBox1.SuspendLayout();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.BackColor = System.Drawing.Color.DarkSalmon;
            this.label1.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label1.ForeColor = System.Drawing.Color.Black;
            this.label1.Location = new System.Drawing.Point(98, 109);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(253, 35);
            this.label1.TabIndex = 0;
            this.label1.Text = "Age";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // label3
            // 
            this.label3.BackColor = System.Drawing.Color.DarkSalmon;
            this.label3.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label3.ForeColor = System.Drawing.Color.Black;
            this.label3.Location = new System.Drawing.Point(98, 158);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(253, 35);
            this.label3.TabIndex = 2;
            this.label3.Text = "Menarche Age";
            this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // label4
            // 
            this.label4.BackColor = System.Drawing.Color.DarkSalmon;
            this.label4.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label4.ForeColor = System.Drawing.Color.Black;
            this.label4.Location = new System.Drawing.Point(98, 218);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(253, 35);
            this.label4.TabIndex = 3;
            this.label4.Text = "First Live Birth Age";
            this.label4.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // label5
            // 
            this.label5.BackColor = System.Drawing.Color.DarkSalmon;
            this.label5.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label5.ForeColor = System.Drawing.Color.Black;
            this.label5.Location = new System.Drawing.Point(98, 275);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(253, 35);
            this.label5.TabIndex = 4;
            this.label5.Text = "Ever had biopsy?";
            this.label5.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // label6
            // 
            this.label6.BackColor = System.Drawing.Color.DarkSalmon;
            this.label6.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label6.ForeColor = System.Drawing.Color.Black;
            this.label6.Location = new System.Drawing.Point(98, 322);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(253, 35);
            this.label6.TabIndex = 5;
            this.label6.Text = "Number of biopsies";
            this.label6.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // label7
            // 
            this.label7.BackColor = System.Drawing.Color.DarkSalmon;
            this.label7.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label7.ForeColor = System.Drawing.Color.Black;
            this.label7.Location = new System.Drawing.Point(98, 371);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(253, 35);
            this.label7.TabIndex = 6;
            this.label7.Text = "First degree relatives";
            this.label7.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // label8
            // 
            this.label8.BackColor = System.Drawing.Color.DarkSalmon;
            this.label8.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label8.ForeColor = System.Drawing.Color.Black;
            this.label8.Location = new System.Drawing.Point(98, 421);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(253, 35);
            this.label8.TabIndex = 7;
            this.label8.Text = "Hyperplasia";
            this.label8.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // label9
            // 
            this.label9.BackColor = System.Drawing.Color.DarkSalmon;
            this.label9.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label9.ForeColor = System.Drawing.Color.Black;
            this.label9.Location = new System.Drawing.Point(98, 478);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(253, 35);
            this.label9.TabIndex = 8;
            this.label9.Text = "Race";
            this.label9.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // AgeBox
            // 
            this.AgeBox.Location = new System.Drawing.Point(433, 109);
            this.AgeBox.Multiline = true;
            this.AgeBox.Name = "AgeBox";
            this.AgeBox.Size = new System.Drawing.Size(115, 35);
            this.AgeBox.TabIndex = 9;
            this.AgeBox.TextChanged += new System.EventHandler(this.AgeBox_TextChanged);
            // 
            // MenBox
            // 
            this.MenBox.Location = new System.Drawing.Point(433, 158);
            this.MenBox.Multiline = true;
            this.MenBox.Name = "MenBox";
            this.MenBox.Size = new System.Drawing.Size(115, 35);
            this.MenBox.TabIndex = 11;
            this.MenBox.TextChanged += new System.EventHandler(this.MenBox_TextChanged);
            // 
            // NoBioBox
            // 
            this.NoBioBox.Location = new System.Drawing.Point(433, 322);
            this.NoBioBox.Multiline = true;
            this.NoBioBox.Name = "NoBioBox";
            this.NoBioBox.Size = new System.Drawing.Size(115, 35);
            this.NoBioBox.TabIndex = 12;
            this.NoBioBox.TextChanged += new System.EventHandler(this.NoBioBox_TextChanged);
            // 
            // RaceBox
            // 
            this.RaceBox.Location = new System.Drawing.Point(433, 477);
            this.RaceBox.Multiline = true;
            this.RaceBox.Name = "RaceBox";
            this.RaceBox.Size = new System.Drawing.Size(115, 35);
            this.RaceBox.TabIndex = 14;
            this.RaceBox.TextChanged += new System.EventHandler(this.RaceBox_TextChanged);
            // 
            // BirthBox
            // 
            this.BirthBox.Location = new System.Drawing.Point(433, 218);
            this.BirthBox.Multiline = true;
            this.BirthBox.Name = "BirthBox";
            this.BirthBox.Size = new System.Drawing.Size(115, 35);
            this.BirthBox.TabIndex = 15;
            this.BirthBox.TextChanged += new System.EventHandler(this.BirthBox_TextChanged);
            // 
            // FirstDegRelBox
            // 
            this.FirstDegRelBox.Location = new System.Drawing.Point(433, 371);
            this.FirstDegRelBox.Multiline = true;
            this.FirstDegRelBox.Name = "FirstDegRelBox";
            this.FirstDegRelBox.Size = new System.Drawing.Size(115, 35);
            this.FirstDegRelBox.TabIndex = 16;
            this.FirstDegRelBox.TextChanged += new System.EventHandler(this.FirstDegRelBox_TextChanged);
            // 
            // button1
            // 
            this.button1.ForeColor = System.Drawing.Color.Black;
            this.button1.Location = new System.Drawing.Point(858, 395);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(149, 52);
            this.button1.TabIndex = 18;
            this.button1.Text = "Calculeaza riscul";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // YesBioButton
            // 
            this.YesBioButton.AutoSize = true;
            this.YesBioButton.ForeColor = System.Drawing.SystemColors.ControlText;
            this.YesBioButton.Location = new System.Drawing.Point(15, 24);
            this.YesBioButton.Name = "YesBioButton";
            this.YesBioButton.Size = new System.Drawing.Size(53, 21);
            this.YesBioButton.TabIndex = 19;
            this.YesBioButton.TabStop = true;
            this.YesBioButton.Text = "Yes";
            this.YesBioButton.UseVisualStyleBackColor = true;
            this.YesBioButton.CheckedChanged += new System.EventHandler(this.YesBioButton_CheckedChanged);
            // 
            // NoBioButton
            // 
            this.NoBioButton.AutoSize = true;
            this.NoBioButton.ForeColor = System.Drawing.SystemColors.ControlText;
            this.NoBioButton.Location = new System.Drawing.Point(98, 24);
            this.NoBioButton.Name = "NoBioButton";
            this.NoBioButton.Size = new System.Drawing.Size(47, 21);
            this.NoBioButton.TabIndex = 20;
            this.NoBioButton.TabStop = true;
            this.NoBioButton.Text = "No";
            this.NoBioButton.UseVisualStyleBackColor = true;
            this.NoBioButton.CheckedChanged += new System.EventHandler(this.NoBioButton_CheckedChanged);
            // 
            // UnknownBioButton
            // 
            this.UnknownBioButton.AutoSize = true;
            this.UnknownBioButton.ForeColor = System.Drawing.SystemColors.ControlText;
            this.UnknownBioButton.Location = new System.Drawing.Point(172, 24);
            this.UnknownBioButton.Name = "UnknownBioButton";
            this.UnknownBioButton.Size = new System.Drawing.Size(87, 21);
            this.UnknownBioButton.TabIndex = 21;
            this.UnknownBioButton.TabStop = true;
            this.UnknownBioButton.Text = "Unknown";
            this.UnknownBioButton.UseVisualStyleBackColor = true;
            this.UnknownBioButton.CheckedChanged += new System.EventHandler(this.UnknownBioButton_CheckedChanged);
            // 
            // UnknownHyp
            // 
            this.UnknownHyp.AutoSize = true;
            this.UnknownHyp.ForeColor = System.Drawing.SystemColors.ControlText;
            this.UnknownHyp.Location = new System.Drawing.Point(172, 14);
            this.UnknownHyp.Name = "UnknownHyp";
            this.UnknownHyp.Size = new System.Drawing.Size(87, 21);
            this.UnknownHyp.TabIndex = 24;
            this.UnknownHyp.TabStop = true;
            this.UnknownHyp.Text = "Unknown";
            this.UnknownHyp.UseVisualStyleBackColor = true;
            this.UnknownHyp.CheckedChanged += new System.EventHandler(this.UnknownHyp_CheckedChanged);
            // 
            // NoHyp
            // 
            this.NoHyp.AutoSize = true;
            this.NoHyp.ForeColor = System.Drawing.SystemColors.ControlText;
            this.NoHyp.Location = new System.Drawing.Point(98, 14);
            this.NoHyp.Name = "NoHyp";
            this.NoHyp.Size = new System.Drawing.Size(47, 21);
            this.NoHyp.TabIndex = 23;
            this.NoHyp.TabStop = true;
            this.NoHyp.Text = "No";
            this.NoHyp.UseVisualStyleBackColor = true;
            this.NoHyp.CheckedChanged += new System.EventHandler(this.NoHyp_CheckedChanged);
            // 
            // YesHyp
            // 
            this.YesHyp.AutoSize = true;
            this.YesHyp.ForeColor = System.Drawing.SystemColors.ControlText;
            this.YesHyp.Location = new System.Drawing.Point(15, 14);
            this.YesHyp.Name = "YesHyp";
            this.YesHyp.Size = new System.Drawing.Size(53, 21);
            this.YesHyp.TabIndex = 22;
            this.YesHyp.TabStop = true;
            this.YesHyp.Text = "Yes";
            this.YesHyp.UseVisualStyleBackColor = true;
            this.YesHyp.CheckedChanged += new System.EventHandler(this.YesHyp_CheckedChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.YesBioButton);
            this.groupBox1.Controls.Add(this.NoBioButton);
            this.groupBox1.Controls.Add(this.UnknownBioButton);
            this.groupBox1.Location = new System.Drawing.Point(433, 259);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(265, 57);
            this.groupBox1.TabIndex = 25;
            this.groupBox1.TabStop = false;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.YesHyp);
            this.panel1.Controls.Add(this.NoHyp);
            this.panel1.Controls.Add(this.UnknownHyp);
            this.panel1.Location = new System.Drawing.Point(433, 412);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(265, 46);
            this.panel1.TabIndex = 26;
            // 
            // label2
            // 
            this.label2.BackColor = System.Drawing.Color.DarkSalmon;
            this.label2.Font = new System.Drawing.Font("Times New Roman", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label2.ForeColor = System.Drawing.Color.Black;
            this.label2.Location = new System.Drawing.Point(102, 29);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(905, 35);
            this.label2.TabIndex = 27;
            this.label2.Text = "Calculeaza riscul de cancer la san utilizand modelul Gail";
            this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // button2
            // 
            this.button2.ForeColor = System.Drawing.Color.Black;
            this.button2.Location = new System.Drawing.Point(858, 460);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(149, 52);
            this.button2.TabIndex = 28;
            this.button2.Text = "Afiseaza riscul";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // comboBox1
            // 
            this.comboBox1.AutoCompleteCustomSource.AddRange(new string[] {
            "1. White",
            "2. African American",
            "3. Hispanic"});
            this.comboBox1.BackColor = System.Drawing.SystemColors.Window;
            this.comboBox1.ForeColor = System.Drawing.SystemColors.WindowText;
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Items.AddRange(new object[] {
            "1. White",
            "2. African American",
            "3. Hispanic"});
            this.comboBox1.Location = new System.Drawing.Point(554, 477);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(144, 24);
            this.comboBox1.TabIndex = 29;
            this.comboBox1.Text = "Choose a number";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FloralWhite;
            this.ClientSize = new System.Drawing.Size(1101, 620);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.FirstDegRelBox);
            this.Controls.Add(this.BirthBox);
            this.Controls.Add(this.RaceBox);
            this.Controls.Add(this.NoBioBox);
            this.Controls.Add(this.MenBox);
            this.Controls.Add(this.AgeBox);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label1);
            this.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Label label1;
        private Label label3;
        private Label label4;
        private Label label5;
        private Label label6;
        private Label label7;
        private Label label8;
        private Label label9;
        private TextBox AgeBox;
        private TextBox MenBox;
        private TextBox NoBioBox;
        private TextBox RaceBox;
        private TextBox BirthBox;
        private TextBox FirstDegRelBox;
        private Button button1;
        private RadioButton YesBioButton;
        private RadioButton NoBioButton;
        private RadioButton UnknownBioButton;
        private RadioButton UnknownHyp;
        private RadioButton NoHyp;
        private RadioButton YesHyp;
        private GroupBox groupBox1;
        private Panel panel1;
        private Label label2;
        private Button button2;
        private ComboBox comboBox1;
    }
}



