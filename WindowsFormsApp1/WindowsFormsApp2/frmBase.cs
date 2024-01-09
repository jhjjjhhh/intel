using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class frmBase : Form
    {
        int EncMode = 0; // 0 : UTF-8 1: ANSI  *** C#전역 변수 설정
        public frmBase() //생성자
        {
            InitializeComponent(); //초기화
            if(EncMode == 0) menuUTF8_Click(null, null);
            else menuANSI_Click(null, null);
        }

        private void btnOPEN_Click(object sender, EventArgs e)
        {
            menuOPEN_Click(sender, e);
        }
        string ReadBuf;
        Encoding enc = Encoding.UTF8; //windows 기본 엔코딩
        private void menuSAVE_Click(object sender, EventArgs e)
        {
            DialogResult ret = saveFileDialog1.ShowDialog(); // c++ 에선 DoModal 사용
            if (ret == DialogResult.OK)
            {
                string fn = saveFileDialog1.FileName;
                FileStream fs = new FileStream(fn, FileMode.Create);
                StreamWriter sw = new StreamWriter(fs,enc);
                sw.Write(tBMEMO.Text);
                sw.Close();
                fs.Close();

            }
        }
        private void menuOPEN_Click(object sender, EventArgs e)
        {
            DialogResult ret = openFileDialog1.ShowDialog(); // c++ 에선 DoModal 사용
            if (ret == DialogResult.OK)
            {
                string fn = openFileDialog1.FileName;
                FileStream fs = new FileStream(fn, FileMode.Open);
                StreamReader sr = new StreamReader(fs,enc);
                tBMEMO.Text = sr.ReadToEnd();
                sr.Close();
                fs.Close();

                //while (true)
                //{
                //    string str = sr.ReadLine(); // fget와 유사 -> 일정한 버퍼안에 데이터를 읽어들이고 버퍼 사이즈를 넘어가면 잘리고 개행까지 읽어준다.
                //    if (str == null) break; //str의 한줄씩 읽다가 더이상 읽을 값이 없으면 while 문 탈출
                //    tBMEMO.Text += str; //그래픽 textbox에 한줄씩 추가
                //}
            }
        }
        private void menuANSI_Click(object sender, EventArgs e)
        {
            sbLabel1.Text = "Mode: ANSI";
            menuANSI.Checked = true;
            menuUTF8.Checked = false;
            enc = Encoding.Default;
             
            
        }

        private void menuUTF8_Click(object sender, EventArgs e)
        {
            sbLabel1.Text = "Mode : UTF-8";
            menuANSI.Checked = false;
            menuUTF8.Checked = true;
            enc = Encoding.UTF8;
        }

        private void menuABOUT_Click(object sender, EventArgs e)
        {
            string s;
            frmAbout frm = new frmAbout();
            DialogResult r = frm.ShowDialog();
            if (r == DialogResult.OK)
            {
                s = "About...OK";
            }
            else s = "About...Cancel";
            sbLabel2.Text = s;
        }
    }
}
