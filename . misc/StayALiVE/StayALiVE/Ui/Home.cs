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

        internal class TempFolder
        {
            internal string SelectedWorld { get; private set; }
            internal string MainDirectory { get; private set; }
            internal TempFolder(string directory,string selectedWorld)
            {
                MainDirectory = directory;
                SelectedWorld = selectedWorld;
            }
            internal string RootDirectory => Path.Combine(MainDirectory, "Missions", SelectedWorld); 
            internal string GetConfigFilePath() => Path.Combine(RootDirectory, Program.Config.Settings.CfgDedicatedServer());
            internal string GetSQMFilePath() =>    Path.Combine(RootDirectory, "mission.sqm");

            internal string BinDirectory => Path.Combine(RootDirectory, "Bin");
            internal string BinMissionDirectory => Path.Combine(BinDirectory, $"Extremo_Mission.{SelectedWorld}");
            internal string BinServerDirectory => Path.Combine(BinDirectory, "Extremo_Server");

            internal bool CopyToTemp()
            {
                //Purge old temp framwork folder
                if (Directory.Exists(BinDirectory)) Directory.Delete(BinDirectory, true);
                Directory.CreateDirectory(BinDirectory);

                //Copy framwork
                Core.Helpers.CopyFilesRecursively(Path.Combine(MainDirectory, $"Extremo_Mission.World"), BinMissionDirectory);
                Core.Helpers.CopyFilesRecursively(Path.Combine(MainDirectory, "Extremo_Server"), BinServerDirectory);

                //Copy SQM into temp framework folder
                File.Copy(GetSQMFilePath(), Path.Combine(BinMissionDirectory, "mission.sqm"));

                return File.Exists(Path.Combine(BinMissionDirectory, "description.ext"));
            }

            internal bool PackAndPrepare()
            {
                Core.Helpers.PackPBO(BinMissionDirectory);
                Core.Helpers.PackPBO(BinServerDirectory);

                return File.Exists($"{BinMissionDirectory}.pbo") && File.Exists($"{BinMissionDirectory}.pbo");
            }

            internal bool CopyFromTemp()
            {
                //Copy mission.pbo from temp folder to server direcrtory
                string newMission = Path.Combine(Program.Config.Settings.ServerDirectory, $"mpmissions\\Extremo_Mission.{SelectedWorld}.pbo.pending");
                if (File.Exists(newMission)) File.Delete(newMission);
                File.Copy(BinMissionDirectory + ".pbo", newMission);

                //Copy server.pbo from temp folder to server direcrtory
                string newServer = Path.Combine(Program.Config.Settings.ServerDirectory, "@ExtremoServer\\addons\\Extremo_Server.pbo.pending");
                if (File.Exists(newServer)) File.Delete(newServer);
                File.Copy(BinServerDirectory + ".pbo", newServer);

                //Copy server.cfg from temp folder to server direcrtory
                string newConfig = Path.Combine(Program.Config.Settings.CfgsPath(), Program.Config.Settings.CfgDedicatedServer() + ".pending");
                if (File.Exists(newConfig)) File.Delete(newConfig);
                File.Copy(GetConfigFilePath(), newConfig);

                return File.Exists(newMission) && File.Exists(newServer) && File.Exists(newConfig);
            }
        }

        private void RepackAll_Tile_Click(object sender, EventArgs e)
        {
            if(Core.Helpers.ApplicationRunning("arma3server_x64.exe") || Core.Helpers.ApplicationRunning("arma3server.exe"))
            { 
                MessageBox.Show("Stop arma3server before continuing", "Error");
                return;
            }

            var Temp = new TempFolder(Program.Config.Settings.FrameworkDirectory,
                MissionFiles_ComboBox.Items[Program.Config.Settings.MissionFile].ToString()
            );

            if (Temp.CopyToTemp())
            {
                if (Temp.PackAndPrepare())
                {
                    if (Temp.CopyFromTemp())
                    {
                        MessageBox.Show("Repack complete!");
                    }
                }
            }
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
