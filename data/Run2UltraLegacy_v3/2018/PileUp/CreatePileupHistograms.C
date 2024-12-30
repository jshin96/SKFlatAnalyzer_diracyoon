#include <TFile.h>
#include <TH1.h>
#include <vector>
#include <iostream>

void CreatePileupHistograms() {
    // File names
    std::vector<std::string> fileNames = {
        "PileupHistogram-goldenJSON-13tev-2018-69200ub-99bins.root",
        "PileupHistogram-goldenJSON-13tev-2018-66000ub-99bins.root",
        "PileupHistogram-goldenJSON-13tev-2018-72400ub-99bins.root"
    };

    // Output histogram names
    std::vector<std::string> outputNames = {"MC_2018_central", "MC_2018_sig_down", "MC_2018_sig_up"};

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
            8.89374611122e-07, 1.1777062868e-05, 3.99725585118e-05, 0.000129888015252, 0.000265224848687,
            0.000313088635109, 0.000353781668514, 0.000508787237162, 0.000873670065767, 0.00147166880932,
            0.00228230649018, 0.00330375581273, 0.00466047608406, 0.00624959203029, 0.00810375867901,
            0.010306521821, 0.0129512453978, 0.0160303925502, 0.0192913204592, 0.0223108613632,
            0.0249798930986, 0.0273973789867, 0.0294402350483, 0.031029854302, 0.0324583524255,
            0.0338264469857, 0.0351267479019, 0.0360320204259, 0.0367489568401, 0.0374133183052,
            0.0380352633799, 0.0386200967002, 0.039124376968, 0.0394201612616, 0.0394673457109,
            0.0391705388069, 0.0384758587461, 0.0372984548399, 0.0356497876549, 0.0334655175178,
            0.030823567063, 0.0278340752408, 0.0246009685048, 0.0212676009273, 0.0180250593982,
            0.0149129830776, 0.0120582333486, 0.00953400069415, 0.00738546929512, 0.00563442079939,
            0.00422052915668, 0.00312446316347, 0.00228717533955, 0.00164064894334, 0.00118425084792,
            0.000847785826565, 0.000603466454784, 0.000419347268964, 0.000291768785963, 0.000199761337863,
            0.000136624574661, 9.46855200945e-05, 6.80243180179e-05, 4.94806013765e-05, 3.53122628249e-05,
            2.556765786e-05, 1.75845711623e-05, 1.23828210848e-05, 9.31669724108e-06, 6.0713272037e-06,
            3.95387384933e-06, 2.02760874107e-06, 1.22535149516e-06, 9.79612472109e-07, 7.61730246474e-07,
            4.2748847738e-07, 2.41170461205e-07, 1.38701083552e-07, 3.37678010922e-08, 0.0,
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
        if (fileNames[i]=="PileupHistogram-goldenJSON-13tev-2018-69200ub-99bins.root"){
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

