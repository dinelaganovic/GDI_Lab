namespace Lab1_Zad_Paint
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.button1 = new System.Windows.Forms.Button();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.stranica1ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.stranica2ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.stranica3ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.settingsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.iconsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem3 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem4 = new System.Windows.Forms.ToolStripMenuItem();
            this.nonToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.button1.Location = new System.Drawing.Point(707, 559);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(114, 23);
            this.button1.TabIndex = 0;
            this.button1.Text = "Dodaj TPL";
            this.button1.UseVisualStyleBackColor = false;
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItem1,
            this.toolsToolStripMenuItem,
            this.settingsToolStripMenuItem,
            this.iconsToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(857, 28);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.stranica1ToolStripMenuItem,
            this.stranica2ToolStripMenuItem,
            this.stranica3ToolStripMenuItem});
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(64, 24);
            this.toolStripMenuItem1.Text = "Home";
            // 
            // stranica1ToolStripMenuItem
            // 
            this.stranica1ToolStripMenuItem.Name = "stranica1ToolStripMenuItem";
            this.stranica1ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.stranica1ToolStripMenuItem.Text = "Stranica1";
            // 
            // stranica2ToolStripMenuItem
            // 
            this.stranica2ToolStripMenuItem.Name = "stranica2ToolStripMenuItem";
            this.stranica2ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.stranica2ToolStripMenuItem.Text = "Stranica2";
            this.stranica2ToolStripMenuItem.Click += new System.EventHandler(this.stranica2ToolStripMenuItem_Click);
            // 
            // stranica3ToolStripMenuItem
            // 
            this.stranica3ToolStripMenuItem.Name = "stranica3ToolStripMenuItem";
            this.stranica3ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.stranica3ToolStripMenuItem.Text = "Stranica3";
            // 
            // toolsToolStripMenuItem
            // 
            this.toolsToolStripMenuItem.Name = "toolsToolStripMenuItem";
            this.toolsToolStripMenuItem.Size = new System.Drawing.Size(58, 24);
            this.toolsToolStripMenuItem.Text = "Tools";
            // 
            // settingsToolStripMenuItem
            // 
            this.settingsToolStripMenuItem.Name = "settingsToolStripMenuItem";
            this.settingsToolStripMenuItem.Size = new System.Drawing.Size(76, 24);
            this.settingsToolStripMenuItem.Text = "Settings";
            // 
            // iconsToolStripMenuItem
            // 
            this.iconsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItem3});
            this.iconsToolStripMenuItem.Name = "iconsToolStripMenuItem";
            this.iconsToolStripMenuItem.Size = new System.Drawing.Size(57, 24);
            this.iconsToolStripMenuItem.Text = "Icons";
            // 
            // toolStripMenuItem3
            // 
            this.toolStripMenuItem3.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItem4});
            this.toolStripMenuItem3.Name = "toolStripMenuItem3";
            this.toolStripMenuItem3.Size = new System.Drawing.Size(100, 26);
            this.toolStripMenuItem3.Text = "1";
            // 
            // toolStripMenuItem4
            // 
            this.toolStripMenuItem4.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.nonToolStripMenuItem});
            this.toolStripMenuItem4.Name = "toolStripMenuItem4";
            this.toolStripMenuItem4.Size = new System.Drawing.Size(111, 26);
            this.toolStripMenuItem4.Text = "3.1";
            // 
            // nonToolStripMenuItem
            // 
            this.nonToolStripMenuItem.Name = "nonToolStripMenuItem";
            this.nonToolStripMenuItem.Size = new System.Drawing.Size(117, 26);
            this.nonToolStripMenuItem.Text = "non";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Silver;
            this.ClientSize = new System.Drawing.Size(857, 594);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem stranica1ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem stranica2ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem toolsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem settingsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem stranica3ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem iconsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem3;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem4;
        private System.Windows.Forms.ToolStripMenuItem nonToolStripMenuItem;
    }
}

