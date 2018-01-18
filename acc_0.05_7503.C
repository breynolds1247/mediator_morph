void acc_0.05_7503()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Dec 12 18:15:33 2017) by ROOT version6.10/08
   TCanvas *c1 = new TCanvas("c1", "c1",10,44,700,500);
   gStyle->SetOptFit(1);
   c1->SetHighLightColor(2);
   c1->Range(-0.5,-0.11375,4.5,1.12375);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH2D *frame__15 = new TH2D("frame__15","",10,0,4,10,0.01,1);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.695,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("frame");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 0      ");
   ptstats_LaTex = ptstats->AddText("Mean x =      0");
   ptstats_LaTex = ptstats->AddText("Mean y =      0");
   ptstats_LaTex = ptstats->AddText("Std Dev x =      0");
   ptstats_LaTex = ptstats->AddText("Std Dev y =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(11111);
   ptstats->Draw();
   frame__15->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(frame__15);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame__15->SetLineColor(ci);
   frame__15->GetXaxis()->SetLabelFont(42);
   frame__15->GetXaxis()->SetLabelSize(0.035);
   frame__15->GetXaxis()->SetTitleSize(0.035);
   frame__15->GetXaxis()->SetTitleFont(42);
   frame__15->GetYaxis()->SetLabelFont(42);
   frame__15->GetYaxis()->SetLabelSize(0.035);
   frame__15->GetYaxis()->SetTitleSize(0.035);
   frame__15->GetYaxis()->SetTitleOffset(0);
   frame__15->GetYaxis()->SetTitleFont(42);
   frame__15->GetZaxis()->SetLabelFont(42);
   frame__15->GetZaxis()->SetLabelSize(0.035);
   frame__15->GetZaxis()->SetTitleSize(0.035);
   frame__15->GetZaxis()->SetTitleFont(42);
   frame__15->Draw("");
   
   Double_t _fx29[6] = {
   0.65,
   0.75,
   0.85,
   0.95,
   0.45,
   0.55};
   Double_t _fy29[6] = {
   0.23,
   0.239,
   0.239,
   0.243,
   0.137,
   0.197};
   TGraph *graph = new TGraph(6,_fx29,_fy29);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(2);
   
   TH1F *Graph_Graph29 = new TH1F("Graph_Graph29","",100,0.4,1);
   Graph_Graph29->SetMinimum(0.1264);
   Graph_Graph29->SetMaximum(0.2536);
   Graph_Graph29->SetDirectory(0);
   Graph_Graph29->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph29->SetLineColor(ci);
   Graph_Graph29->GetXaxis()->SetLabelFont(42);
   Graph_Graph29->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph29->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph29->GetXaxis()->SetTitleFont(42);
   Graph_Graph29->GetYaxis()->SetLabelFont(42);
   Graph_Graph29->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph29->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph29->GetYaxis()->SetTitleOffset(0);
   Graph_Graph29->GetYaxis()->SetTitleFont(42);
   Graph_Graph29->GetZaxis()->SetLabelFont(42);
   Graph_Graph29->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph29->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph29->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph29);
   
   
   TF1 *mp30 = new TF1("mp","[0]/(1+exp(-(x-[1])*[2]))*(1+exp(-(x-[3])*[4]))",0.39,2);
   mp30->SetFillColor(19);
   mp30->SetFillStyle(0);
   mp30->SetLineColor(2);
   mp30->SetLineWidth(2);
   mp30->SetChisquare(1.277754e-05);
   mp30->SetNDF(1);
   mp30->GetXaxis()->SetLabelFont(42);
   mp30->GetXaxis()->SetLabelSize(0.035);
   mp30->GetXaxis()->SetTitleSize(0.035);
   mp30->GetXaxis()->SetTitleFont(42);
   mp30->GetYaxis()->SetLabelFont(42);
   mp30->GetYaxis()->SetLabelSize(0.035);
   mp30->GetYaxis()->SetTitleSize(0.035);
   mp30->GetYaxis()->SetTitleOffset(0);
   mp30->GetYaxis()->SetTitleFont(42);
   mp30->SetParameter(0,0.1217392);
   mp30->SetParError(0,0.002396984);
   mp30->SetParLimits(0,0,0);
   mp30->SetParameter(1,0.4299646);
   mp30->SetParError(1,0.00508597);
   mp30->SetParLimits(1,0,0);
   mp30->SetParameter(2,12.45266);
   mp30->SetParError(2,0.9549177);
   mp30->SetParLimits(2,0,0);
   mp30->SetParameter(3,10.45546);
   mp30->SetParError(3,0.04431606);
   mp30->SetParLimits(3,1,20);
   mp30->SetParameter(4,-0.0006701661);
   mp30->SetParError(4,0.3557678);
   mp30->SetParLimits(4,-100,0);
   graph->GetListOfFunctions()->Add(mp30);
   graph->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
