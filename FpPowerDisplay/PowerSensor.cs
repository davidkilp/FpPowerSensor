using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace FpPowerDisplay
{
    internal class PowerSensor
    {
        #region dllImports
        // FpPowerSensors c++ DLL here - needs a project reference to this dll in C# project also
        private const string _dllImportPath = @"FpPwrSensorDll.dll";

        // External C++ Functions 
        [DllImport(_dllImportPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr FpPwr_Instantiate();

        [DllImport(_dllImportPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern double FpPwr_getPower(IntPtr p);

        [DllImport(_dllImportPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern double FpPwr_getShuntVoltage(IntPtr p);
        
        [DllImport(_dllImportPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern double FpPwr_getBusVoltage(IntPtr p);

        [DllImport(_dllImportPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern double FpPwr_getCurrent(IntPtr p);
        #endregion

    }
}
