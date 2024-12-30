import ROOT

# Open the ROOT file
file_path = "/gv0/DATA/SKFlat/Run2UltraLegacy_v3/2018/DATA/DoubleMuon/periodA/220618_054835/0000/SKFlatNtuple_2018_DATA_10.root"
#file_path = "/gv0/DATA/SKFlat/Run2UltraLegacy_v3/2018/DATA/SingleMuon/periodA/220618_054402/0000/SKFlatNtuple_2018_DATA_10.root"
root_file = ROOT.TFile.Open(file_path)

# Access the TDirectory and TTree
recoTree = root_file.Get("recoTree")
tree = recoTree.Get("SKFlat")

# Loop through the entries and get the HLT_TriggerName
for i, entry in enumerate(tree):
    # Access the vector<string> branch
    if i > 50: break
    trigger_names = entry.HLT_TriggerName
    
    # Convert to a Python list for easier handling
    trigger_list = [trigger_name for trigger_name in trigger_names]
    # Print the list of triggers for this entry
    print(trigger_list)

# Close the file
root_file.Close()

