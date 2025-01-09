namespace FpPowerDisplay
{
    public partial class Form1 : Form
    {
        IntPtr pSensor = 0;
        bool doUpdate = false;

        public Form1()
        {
            InitializeComponent();
            labelState.Text = "stopped";
            buttonStart.Enabled = true;
            buttonStop.Enabled = false;
            if (!InitPowerSensor())
            {
                // Kill the application
               // System.Environment.Exit(1);
            }
        }

        private bool InitPowerSensor()
        {

            try
            {
                pSensor = PowerSensor.FpPwr_Instantiate();
                UpdateReadings();
            } 
            catch (Exception ex)
            {
                MessageBox.Show("Power Sensor hardware not detected.\nRestart application or system\n" + ex.Message);
                labelState.Text = "Power Sensor hardware not detected.";
                buttonStart.Enabled = false;
                return false;
            }

            return true;
        }

        private void UpdateReadings()
        {
            labelBusV.Text = PowerSensor.FpPwr_getBusVoltage(pSensor).ToString();
            labelCurrent.Text = PowerSensor.FpPwr_getCurrent(pSensor).ToString();
            labelPower.Text = PowerSensor.FpPwr_getPower(pSensor).ToString();
            labelShuntV.Text = PowerSensor.FpPwr_getShuntVoltage(pSensor).ToString();
        }

        // start background task
        private async void buttonStart_Click(object sender, EventArgs e)
        {
            labelState.Text = "running";
            buttonStart.Enabled = false;
            buttonStop.Enabled = true;
            doUpdate = true;

            // start asynchronous operation
            await Task.Run(() =>
            {
                TimeConsumingOperation();
            });
        }

        // Cancel background task
        private void buttonStop_Click(object sender, EventArgs e)
        {
            labelState.Text = "stopped";
            buttonStart.Enabled = true;
            buttonStop.Enabled = false;
            doUpdate = false;
        }

        private void InvokeUI(Action a)
        {
            this.BeginInvoke(new MethodInvoker(a));
        }

        // time consuming operation
        private void TimeConsumingOperation()
        {

            while (doUpdate)
            {
                InvokeUI(() =>
                {
                    UpdateReadings();

                });
                System.Threading.Thread.Sleep(2000);
            }
        }
    }

}
