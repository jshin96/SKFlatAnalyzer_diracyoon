#include <TFile.h>
#include <TH1.h>
#include <vector>
#include <iostream>

void CreatePileupHistograms() {
    // File names
    std::vector<std::string> fileNames = {
        "PileupHistogram-goldenJSON-13tev-2017-69200ub-99bins.root",
        "PileupHistogram-goldenJSON-13tev-2017-66000ub-99bins.root",
        "PileupHistogram-goldenJSON-13tev-2017-72400ub-99bins.root"
    };

    // Output histogram names
    std::vector<std::string> outputNames = {"MC_2017_central", "MC_2017_sig_down", "MC_2017_sig_up"};

    // Output ROOT file
    TFile *outputFile = new TFile("output_pileup_histograms.root", "RECREATE");

    for (size_t i = 0; i < fileNames.size(); ++i) {
        // Open input file
        TFile *inputFile = TFile::Open(fileNames[i].c_str(), "READ");
        if (!inputFile || inputFile->IsZombie()) {
            std::cerr << "Error: Cannot open file " << fileNames[i] << std::endl;
            continue;
        }

        // Get and normalize the "pileup" histogram
        TH1 *pileupHist = dynamic_cast<TH1*>(inputFile->Get("pileup"));
        if (!pileupHist) {
            std::cerr << "Error: Histogram 'pileup' not found in " << fileNames[i] << std::endl;
            inputFile->Close();
            continue;
        }
        pileupHist->Scale(1.0 / pileupHist->Integral());
        pileupHist->SetName("DATA_PU");

        // Create a vector with the same number of bins as "pileup"
        std::vector<double> binValues = {
            1.1840841518e-05, 3.46661037703e-05, 8.98772521472e-05, 7.47400487733e-05, 0.000123005176624,
            0.000156501700614, 0.000154660478659, 0.000177496185603, 0.000324149805611, 0.000737524009713,
            0.00140432980253, 0.00244424508696, 0.00380027898037, 0.00541093042612, 0.00768803501793,
            0.010828224552, 0.0146608623707, 0.01887739113, 0.0228418813823, 0.0264817796874,
            0.0294637401336, 0.0317960986171, 0.0336645950831, 0.0352638818387, 0.036869429333,
            0.0382797316998, 0.039386705577, 0.0398389681346, 0.039646211131, 0.0388392805703,
            0.0374195678161, 0.0355377892706, 0.0333383902828, 0.0308286549265, 0.0282914440969,
            0.0257860718304, 0.02341635055, 0.0213126338243, 0.0195035612803, 0.0181079838989,
            0.0171991315458, 0.0166377598339, 0.0166445341361, 0.0171943735369, 0.0181980997278,
            0.0191339792146, 0.0198518804356, 0.0199714909193, 0.0194616474094, 0.0178626975229,
            0.0153296785464, 0.0126789254325, 0.0100766041988, 0.00773867100481, 0.00592386091874,
            0.00434706240169, 0.00310217013427, 0.00213213401899, 0.0013996000761, 0.000879148859271,
            0.000540866009427, 0.000326115560156, 0.000193965828516, 0.000114607606623, 6.74262828734e-05,
            3.97805301078e-05, 2.19948704638e-05, 9.72007976207e-06, 4.26179259146e-06, 2.80015581327e-06,
            1.14675436465e-06, 2.52452411995e-07, 9.08394910044e-08, 1.14291987912e-08, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0
        };

        // Check the vector size matches the number of bins
        if (binValues.size() != static_cast<size_t>(pileupHist->GetNbinsX())) {
            std::cerr << "Error: Vector size does not match number of bins!" << std::endl;
            inputFile->Close();
            continue;
        }

        // Create "MC_PU" histogram
        TH1 *mcPUHist = static_cast<TH1*>(pileupHist->Clone("MC_PU"));
        mcPUHist->Reset();
        for (size_t j = 0; j < binValues.size(); ++j) {
            mcPUHist->SetBinContent(j + 1, binValues[j]);
        }

        // Create "central/sig_down/sig_up" histogram
        TH1 *ratioHist = static_cast<TH1*>(pileupHist->Clone(outputNames[i].c_str()));
        ratioHist->Divide(mcPUHist);

        // Write histograms to output file
        outputFile->cd();
        ratioHist->Write();
        if (fileNames[i]=="PileupHistogram-goldenJSON-13tev-2017-69200ub-99bins.root"){
            pileupHist->Write();
            mcPUHist->Write();
        }
        // Close input file
        inputFile->Close();
    }

    // Close output file
    outputFile->Close();

    std::cout << "Histograms created and saved in 'output_pileup_histograms.root'." << std::endl;
}

