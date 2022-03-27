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

namespace StayALiVE
{
    internal partial class Home : Form
    {
        internal static Home GetInstance() { return new Home(); }
        
        internal Home()
        {
            InitializeComponent();
            Program.Config.Settings.MissionFiles.ForEach(missionFile => MissionFiles_ComboBox.Items.Add(missionFile));
            if (MissionFiles_ComboBox.Items.Count > 0) 
                MissionFiles_ComboBox.SelectedIndex = Program.Config.Settings.MissionFile; 
            else
                MissionFiles_ComboBox.Enabled = false;
        }
         
        private void Wiki_Tile_Click(object sender, EventArgs e) => System.Diagnostics.Process.Start("https://community.bistudio.com/wiki/Category:Arma_3");

        private void Update_Tile_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Feature Coming Soon!");
        }

        private void Download_Tile_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Feature Coming Soon!");
        }

        private void MissionFiles_ComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            Program.Config.Settings.MissionFile = MissionFiles_ComboBox.SelectedIndex;
            Program.Config.Save(Program.Config.Settings);
        }

        private void RepackAll_Tile_Click(object sender, EventArgs e)
        {
            if(Core.Helpers.ApplicationRunning("arma3server_x64.exe") || Core.Helpers.ApplicationRunning("arma3server.exe"))
            { 
                MessageBox.Show("Stop arma3server before continuing", "Error");
                return;
            }

            string selectedWorld = MissionFiles_ComboBox.Items[Program.Config.Settings.MissionFile].ToString(); 
            string missionsPath = Path.Combine(Program.Config.Settings.FrameworkDirectory, $"Missions");
            string BinPath = Path.Combine(missionsPath, $"Bin");
            string TempMissionPath = Path.Combine(BinPath,  $"Extremo_Mission.{selectedWorld}");
            string TempServerPath = Path.Combine(BinPath, "Extremo_Server");
            string TempConfigPath = Path.Combine(missionsPath, selectedWorld, Program.Config.Settings.CfgDedicatedServer());
            string TempSQMPath = Path.Combine(missionsPath, selectedWorld, $"mission.sqm");

            //Purge old folder
            if (Directory.Exists(TempMissionPath)) Directory.Delete(TempMissionPath, true);
            Directory.CreateDirectory(TempMissionPath);

            //Copy Framwork
            Core.Helpers.CopyFilesRecursively(Path.Combine(Program.Config.Settings.FrameworkDirectory, $"Extremo_Mission.World"), TempMissionPath);
            Core.Helpers.CopyFilesRecursively(Path.Combine(Program.Config.Settings.FrameworkDirectory, "Extremo_Server"), TempServerPath);

            //Copy Mission SQM into temp mission folder
            File.Copy(TempSQMPath, Path.Combine(TempMissionPath, $"mission.sqm"));

            //Pack Framework in Temp folder
            Core.Helpers.PackPBO(TempMissionPath);
            Core.Helpers.PackPBO(TempServerPath);

            //Move Framework from Temp folder to server
            string newMission = Path.Combine(Program.Config.Settings.ServerDirectory, $"mpmissions\\Extremo_Mission.{selectedWorld}.pbo.pending");
            if (File.Exists(newMission)) File.Delete(newMission);
            File.Copy(TempMissionPath + ".pbo", newMission);

            string newServer = Path.Combine(Program.Config.Settings.ServerDirectory, "@ExtremoServer\\addons\\Extremo_Server.pbo.pending");
            if (File.Exists(newServer)) File.Delete(newServer);
            File.Copy(TempServerPath + ".pbo", newServer);

            string newConfig = Path.Combine(Program.Config.Settings.CfgsPath(), Program.Config.Settings.CfgDedicatedServer() + ".pending");
            if (File.Exists(newConfig)) File.Delete(newConfig);
            File.Copy(TempConfigPath, newConfig);

            MessageBox.Show("Repack complete!");
        }

        private void RPT_Tile_Click(object sender, EventArgs e)
        {
            var RPTDirectoryPath = Program.Config.Settings.ProfilesPath();
            var RPTDirectoryInfo = new DirectoryInfo(RPTDirectoryPath); 
            var RPTFile = RPTDirectoryInfo.GetFiles("*.rpt").OrderByDescending(f => f.LastWriteTime).First(); 
            System.Diagnostics.Process.Start(RPTFile.FullName);
        }

        private void StartSwitch_CheckedChanged(object sender, System.EventArgs e) => Program.Server.SwitchOnlineState(sender, e);
    }
}
