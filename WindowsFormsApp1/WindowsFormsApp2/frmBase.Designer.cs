namespace WindowsFormsApp2
{
    partial class frmBase
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.tBMEMO = new System.Windows.Forms.TextBox();
            this.sbSTRIP = new System.Windows.Forms.StatusStrip();
            this.sbLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.sbLabel2 = new System.Windows.Forms.ToolStripStatusLabel();
            this.sbLabel3 = new System.Windows.Forms.ToolStripStatusLabel();
            this.btnOPEN = new System.Windows.Forms.Button();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.파일ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuNEW = new System.Windows.Forms.ToolStripMenuItem();
            this.menuOPEN = new System.Windows.Forms.ToolStripMenuItem();
            this.menuSAVE = new System.Windows.Forms.ToolStripMenuItem();
            this.menuEXIT = new System.Windows.Forms.ToolStripMenuItem();
            this.편집ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuFIND = new System.Windows.Forms.ToolStripMenuItem();
            this.menuREPLACE = new System.Windows.Forms.ToolStripMenuItem();
            this.보기ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuFONT = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripSeparator();
            this.menuANSI = new System.Windows.Forms.ToolStripMenuItem();
            this.menuUTF8 = new System.Windows.Forms.ToolStripMenuItem();
            this.도움말ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuABOUT = new System.Windows.Forms.ToolStripMenuItem();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.sbSTRIP.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tBMEMO
            // 
            this.tBMEMO.AcceptsReturn = true;
            this.tBMEMO.AcceptsTab = true;
            this.tBMEMO.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tBMEMO.Location = new System.Drawing.Point(12, 27);
            this.tBMEMO.Multiline = true;
            this.tBMEMO.Name = "tBMEMO";
            this.tBMEMO.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.tBMEMO.Size = new System.Drawing.Size(707, 378);
            this.tBMEMO.TabIndex = 0;
            // 
            // sbSTRIP
            // 
            this.sbSTRIP.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.sbLabel1,
            this.sbLabel2,
            this.sbLabel3});
            this.sbSTRIP.Location = new System.Drawing.Point(0, 408);
            this.sbSTRIP.Name = "sbSTRIP";
            this.sbSTRIP.Size = new System.Drawing.Size(810, 22);
            this.sbSTRIP.TabIndex = 1;
            this.sbSTRIP.Text = "statusStrip1";
            // 
            // sbLabel1
            // 
            this.sbLabel1.Name = "sbLabel1";
            this.sbLabel1.Size = new System.Drawing.Size(11, 17);
            this.sbLabel1.Text = " ";
            // 
            // sbLabel2
            // 
            this.sbLabel2.Name = "sbLabel2";
            this.sbLabel2.Size = new System.Drawing.Size(11, 17);
            this.sbLabel2.Text = " ";
            // 
            // sbLabel3
            // 
            this.sbLabel3.Name = "sbLabel3";
            this.sbLabel3.Size = new System.Drawing.Size(11, 17);
            this.sbLabel3.Text = " ";
            // 
            // btnOPEN
            // 
            this.btnOPEN.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnOPEN.BackColor = System.Drawing.Color.Red;
            this.btnOPEN.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btnOPEN.ForeColor = System.Drawing.Color.Yellow;
            this.btnOPEN.Location = new System.Drawing.Point(725, 27);
            this.btnOPEN.Name = "btnOPEN";
            this.btnOPEN.Size = new System.Drawing.Size(73, 43);
            this.btnOPEN.TabIndex = 2;
            this.btnOPEN.Text = "button1";
            this.btnOPEN.UseVisualStyleBackColor = false;
            this.btnOPEN.Click += new System.EventHandler(this.btnOPEN_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.파일ToolStripMenuItem,
            this.편집ToolStripMenuItem,
            this.보기ToolStripMenuItem,
            this.도움말ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(810, 24);
            this.menuStrip1.TabIndex = 3;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 파일ToolStripMenuItem
            // 
            this.파일ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuNEW,
            this.menuOPEN,
            this.menuSAVE,
            this.menuEXIT});
            this.파일ToolStripMenuItem.Name = "파일ToolStripMenuItem";
            this.파일ToolStripMenuItem.Size = new System.Drawing.Size(43, 20);
            this.파일ToolStripMenuItem.Text = "파일";
            // 
            // menuNEW
            // 
            this.menuNEW.Name = "menuNEW";
            this.menuNEW.Size = new System.Drawing.Size(103, 22);
            this.menuNEW.Text = "New";
            // 
            // menuOPEN
            // 
            this.menuOPEN.Name = "menuOPEN";
            this.menuOPEN.Size = new System.Drawing.Size(103, 22);
            this.menuOPEN.Text = "Open";
            this.menuOPEN.Click += new System.EventHandler(this.menuOPEN_Click);
            // 
            // menuSAVE
            // 
            this.menuSAVE.Name = "menuSAVE";
            this.menuSAVE.Size = new System.Drawing.Size(180, 22);
            this.menuSAVE.Text = "Save";
            this.menuSAVE.Click += new System.EventHandler(this.menuSAVE_Click);
            // 
            // menuEXIT
            // 
            this.menuEXIT.Name = "menuEXIT";
            this.menuEXIT.Size = new System.Drawing.Size(103, 22);
            this.menuEXIT.Text = "Exit";
            // 
            // 편집ToolStripMenuItem
            // 
            this.편집ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuFIND,
            this.menuREPLACE});
            this.편집ToolStripMenuItem.Name = "편집ToolStripMenuItem";
            this.편집ToolStripMenuItem.Size = new System.Drawing.Size(43, 20);
            this.편집ToolStripMenuItem.Text = "편집";
            // 
            // menuFIND
            // 
            this.menuFIND.Name = "menuFIND";
            this.menuFIND.Size = new System.Drawing.Size(110, 22);
            this.menuFIND.Text = "찾기";
            // 
            // menuREPLACE
            // 
            this.menuREPLACE.Name = "menuREPLACE";
            this.menuREPLACE.Size = new System.Drawing.Size(110, 22);
            this.menuREPLACE.Text = "바꾸기";
            // 
            // 보기ToolStripMenuItem
            // 
            this.보기ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuFONT,
            this.toolStripMenuItem1,
            this.menuANSI,
            this.menuUTF8});
            this.보기ToolStripMenuItem.Name = "보기ToolStripMenuItem";
            this.보기ToolStripMenuItem.Size = new System.Drawing.Size(43, 20);
            this.보기ToolStripMenuItem.Text = "보기";
            // 
            // menuFONT
            // 
            this.menuFONT.Name = "menuFONT";
            this.menuFONT.Size = new System.Drawing.Size(180, 22);
            this.menuFONT.Text = "글꼴";
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(177, 6);
            // 
            // menuANSI
            // 
            this.menuANSI.Name = "menuANSI";
            this.menuANSI.Size = new System.Drawing.Size(180, 22);
            this.menuANSI.Text = "ANSI";
            this.menuANSI.Click += new System.EventHandler(this.menuANSI_Click);
            // 
            // menuUTF8
            // 
            this.menuUTF8.Name = "menuUTF8";
            this.menuUTF8.Size = new System.Drawing.Size(180, 22);
            this.menuUTF8.Text = "UTF-8";
            this.menuUTF8.Click += new System.EventHandler(this.menuUTF8_Click);
            // 
            // 도움말ToolStripMenuItem
            // 
            this.도움말ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuABOUT});
            this.도움말ToolStripMenuItem.Name = "도움말ToolStripMenuItem";
            this.도움말ToolStripMenuItem.Size = new System.Drawing.Size(55, 20);
            this.도움말ToolStripMenuItem.Text = "도움말";
            // 
            // menuABOUT
            // 
            this.menuABOUT.Name = "menuABOUT";
            this.menuABOUT.Size = new System.Drawing.Size(180, 22);
            this.menuABOUT.Text = "About";
            this.menuABOUT.Click += new System.EventHandler(this.menuABOUT_Click);
            // 
            // saveFileDialog1
            // 
            this.saveFileDialog1.FileName = "saveFileDialog1";
            // 
            // frmBase
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(810, 430);
            this.Controls.Add(this.btnOPEN);
            this.Controls.Add(this.sbSTRIP);
            this.Controls.Add(this.menuStrip1);
            this.Controls.Add(this.tBMEMO);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "frmBase";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "My C# Memo ver1.0";
            this.sbSTRIP.ResumeLayout(false);
            this.sbSTRIP.PerformLayout();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox tBMEMO;
        private System.Windows.Forms.StatusStrip sbSTRIP;
        private System.Windows.Forms.ToolStripStatusLabel sbLabel1;
        private System.Windows.Forms.ToolStripStatusLabel sbLabel2;
        private System.Windows.Forms.ToolStripStatusLabel sbLabel3;
        private System.Windows.Forms.Button btnOPEN;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 파일ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem menuNEW;
        private System.Windows.Forms.ToolStripMenuItem menuOPEN;
        private System.Windows.Forms.ToolStripMenuItem menuSAVE;
        private System.Windows.Forms.ToolStripMenuItem menuEXIT;
        private System.Windows.Forms.ToolStripMenuItem 편집ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem menuFIND;
        private System.Windows.Forms.ToolStripMenuItem menuREPLACE;
        private System.Windows.Forms.ToolStripMenuItem 보기ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem menuFONT;
        private System.Windows.Forms.ToolStripSeparator toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem menuANSI;
        private System.Windows.Forms.ToolStripMenuItem menuUTF8;
        private System.Windows.Forms.ToolStripMenuItem 도움말ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem menuABOUT;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
    }
}

