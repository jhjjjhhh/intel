using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormTest03_Paint
{
    public partial class frmPaint : Form
    {
        Graphics g = null;
        Pen pen = null;
        Brush brush = null;

        int dMod = 0; // 0 : Not | 1 : freeDraw | 2 : LineDraw | 3: RectDraw | 4: CircleDraw | 5: Text
        int dFlag = 0; // 0 : Open | 1 : Pressed : 마우스 버튼
        Point p1, p2, p3;

        public frmPaint()
        {
            InitializeComponent();
            g = Canvas.CreateGraphics();
            pen = new Pen(Color.Red, 3.0f);
        }
        
        private void Canvas_MouseUp(object sender, MouseEventArgs e)
        {
            dFlag = 0;
        }

        private void Canvas_MouseDown(object sender, MouseEventArgs e)
        {
            dFlag = 1;
            p1 = e.Location; //마우스 버튼이 눌리면 바로 좌표를 p1에 담는다.
        }
        private void Canvas_MouseMove(object sender, MouseEventArgs e)
        {
            string str = $"{e.X}, {e.Y} px";
            sbLabel1.Text = str;
            if (dFlag == 0) return;
            switch (dMod)
            {
                case 1: //pen draw
                    g.DrawLine(pen, p1, e.Location);
                    p1 = e.Location;
                    break;
                case 2: //line draw

                case 3: //rect draw

                case 4: //circle draw

                default: break;

            }
        }
        private void mnuDraw_Click(object sender, EventArgs e)
        {
            dMod = 1; //자유 그리기
            sbLabel4.Text = "연필 그리기";
        }

        private void mnuLine_Click(object sender, EventArgs e)
        {
            dMod = 2; //선 그리기
            sbLabel4.Text = "직선 그리기";
        }

        private void mnuRect_Click(object sender, EventArgs e)
        {
            dMod = 3; //사각형 그리기
            sbLabel4.Text = "사각형 그리기";
        }

        private void mnuCircle_Click(object sender, EventArgs e)
        {
            dMod = 4; // 원 그리기
            sbLabel4.Text = "원 그리기";
        }

        private void mnuText_Click(object sender, EventArgs e)
        {
            dMod = 5; //문자 쓰기
            sbLabel4.Text = "문자 쓰기";
        }



        private void mnuErase_Click(object sender, EventArgs e)
        {

        }
        /* 좌표계 함수 
            호출한 곳의 obj(sender) , 이벤트 처리에 필요한 후속 agument (e)
            e.X e.Y 마우스 좌표 X,Y 이며 str 에 저장하여 사용자에게 출력한다
            좌상이 기준 (0, 0)
        */


        /* 그리기 함수
            호출한 곳의 obj(sender) , 이벤트 처리에 필요한 후속 agument (e)
            그래픽 개체를 만든다.
            현재 사용하지 않음
        */
        private void Canvas_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics; //

            Pen pen = new Pen(Color.Red); //DrawLine의 매개변수

            Point p1 = new Point(Left,Top);
            Point p2 = new Point(Right,Bottom);
            Point p3 = new Point(Left,Bottom);
            Point p4 = new Point(Right,Top);
            g.DrawLine(pen, p1, p2);
            g.DrawLine(pen, p3, p4);
        }
    }
}
