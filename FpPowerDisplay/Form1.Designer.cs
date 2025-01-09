namespace FpPowerDisplay
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            label1 = new Label();
            labelPower = new Label();
            labelBusV = new Label();
            label3 = new Label();
            labelShuntV = new Label();
            label4 = new Label();
            labelCurrent = new Label();
            label5 = new Label();
            buttonStart = new Button();
            buttonStop = new Button();
            label2 = new Label();
            labelState = new Label();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label1.Location = new Point(32, 28);
            label1.Name = "label1";
            label1.Size = new Size(112, 30);
            label1.TabIndex = 0;
            label1.Text = "Power (W):";
            // 
            // labelPower
            // 
            labelPower.AutoSize = true;
            labelPower.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 0);
            labelPower.Location = new Point(217, 28);
            labelPower.Name = "labelPower";
            labelPower.Size = new Size(51, 30);
            labelPower.TabIndex = 1;
            labelPower.Text = "N/A";
            // 
            // labelBusV
            // 
            labelBusV.AutoSize = true;
            labelBusV.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 0);
            labelBusV.Location = new Point(217, 58);
            labelBusV.Name = "labelBusV";
            labelBusV.Size = new Size(51, 30);
            labelBusV.TabIndex = 3;
            labelBusV.Text = "N/A";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label3.Location = new Point(32, 58);
            label3.Name = "label3";
            label3.Size = new Size(158, 30);
            label3.TabIndex = 2;
            label3.Text = "Bus Voltage (V):";
            // 
            // labelShuntV
            // 
            labelShuntV.AutoSize = true;
            labelShuntV.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 0);
            labelShuntV.Location = new Point(217, 88);
            labelShuntV.Name = "labelShuntV";
            labelShuntV.Size = new Size(51, 30);
            labelShuntV.TabIndex = 5;
            labelShuntV.Text = "N/A";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label4.Location = new Point(32, 88);
            label4.Name = "label4";
            label4.Size = new Size(179, 30);
            label4.TabIndex = 4;
            label4.Text = "Shunt Voltage (V):";
            // 
            // labelCurrent
            // 
            labelCurrent.AutoSize = true;
            labelCurrent.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 0);
            labelCurrent.Location = new Point(217, 118);
            labelCurrent.Name = "labelCurrent";
            labelCurrent.Size = new Size(51, 30);
            labelCurrent.TabIndex = 7;
            labelCurrent.Text = "N/A";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label5.Location = new Point(32, 118);
            label5.Name = "label5";
            label5.Size = new Size(119, 30);
            label5.TabIndex = 6;
            label5.Text = "Current (A):";
            // 
            // buttonStart
            // 
            buttonStart.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 0);
            buttonStart.Location = new Point(32, 189);
            buttonStart.Name = "buttonStart";
            buttonStart.Size = new Size(96, 54);
            buttonStart.TabIndex = 8;
            buttonStart.Text = "Start";
            buttonStart.UseVisualStyleBackColor = true;
            buttonStart.Click += buttonStart_Click;
            // 
            // buttonStop
            // 
            buttonStop.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 0);
            buttonStop.Location = new Point(217, 189);
            buttonStop.Name = "buttonStop";
            buttonStop.Size = new Size(96, 54);
            buttonStop.TabIndex = 9;
            buttonStop.Text = "Stop";
            buttonStop.UseVisualStyleBackColor = true;
            buttonStop.Click += buttonStop_Click;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label2.Location = new Point(32, 165);
            label2.Name = "label2";
            label2.Size = new Size(154, 21);
            label2.TabIndex = 10;
            label2.Text = "Continuous Updates:";
            // 
            // labelState
            // 
            labelState.AutoSize = true;
            labelState.Location = new Point(37, 278);
            labelState.Name = "labelState";
            labelState.Size = new Size(29, 15);
            labelState.TabIndex = 11;
            labelState.Text = "N/A";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(361, 332);
            Controls.Add(labelState);
            Controls.Add(label2);
            Controls.Add(buttonStop);
            Controls.Add(buttonStart);
            Controls.Add(labelCurrent);
            Controls.Add(label5);
            Controls.Add(labelShuntV);
            Controls.Add(label4);
            Controls.Add(labelBusV);
            Controls.Add(label3);
            Controls.Add(labelPower);
            Controls.Add(label1);
            Name = "Form1";
            Text = "Power Sensor";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Label labelPower;
        private Label labelBusV;
        private Label label3;
        private Label labelShuntV;
        private Label label4;
        private Label labelCurrent;
        private Label label5;
        private Button buttonStart;
        private Button buttonStop;
        private Label label2;
        private Label labelState;
    }
}
