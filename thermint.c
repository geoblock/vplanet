/********************** THERMINT.C **********************/
/*
 * Peter Driscoll 6/1/15
 *
 * Thermal evolution of the interior (mantle+core)
 *
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "vplanet.h"

void  InitializeControlThermint(CONTROL *control) {
  /* Nothing for now, but this subroutine is necessary for module loops. */
}

void BodyCopyThermint(BODY *dest,BODY *src,int foo,int iBody) {
  dest[iBody].dTMan = src[iBody].dTMan;
  dest[iBody].dTCore = src[iBody].dTCore;
}

void InitializeBodyThermint(BODY *body,CONTROL *control,UPDATE *update,int iBody,int iModule) {
}

void InitializeUpdateTmpBodyThermint(BODY *body,CONTROL *control,UPDATE *update,int iBody) {
}

/**************** RADHEAT options ********************/

/* Initial Mantle & Core Temperature */

void ReadTMan(BODY *body,CONTROL *control,FILES *files,OPTIONS *options,SYSTEM *system,int iFile) {
  int lTmp=-1;
  double dTmp;

  AddOptionDouble(files->Infile[iFile].cIn,options->cName,&dTmp,&lTmp,control->Io.iVerbose);
  if (lTmp >= 0) {   //if line num of option ge 0
    NotPrimaryInput(iFile,options->cName,files->Infile[iFile].cIn,lTmp,control->Io.iVerbose);
    if (dTmp < 0)   //if input value lt 0
      body[iFile-1].dTMan = dTmp*dNegativeDouble(*options,files->Infile[iFile].cIn,control->Io.iVerbose);
   else
       body[iFile-1].dTMan = dTmp*fdUnitsTemp(control->Units[iFile].iTime,control->Units[iFile].iMass,control->Units[iFile].iLength);
    UpdateFoundOption(&files->Infile[iFile],options,lTmp,iFile);
  } else
      if (iFile > 0)  //if line num not ge 0, then if iFile gt 0, then set default.
      body[iFile-1].dTMan = options->dDefault;
}

void ReadTCore(BODY *body,CONTROL *control,FILES *files,OPTIONS *options,SYSTEM *system,int iFile) {
  int lTmp=-1;
  double dTmp;

  AddOptionDouble(files->Infile[iFile].cIn,options->cName,&dTmp,&lTmp,control->Io.iVerbose);
  if (lTmp >= 0) {   //if line num of option ge 0
    NotPrimaryInput(iFile,options->cName,files->Infile[iFile].cIn,lTmp,control->Io.iVerbose);
    if (dTmp < 0)   //if input value lt 0
      body[iFile-1].dTCore = dTmp*dNegativeDouble(*options,files->Infile[iFile].cIn,control->Io.iVerbose);
   else
       body[iFile-1].dTCore = dTmp*fdUnitsTemp(control->Units[iFile].iTime,control->Units[iFile].iMass,control->Units[iFile].iLength);
    UpdateFoundOption(&files->Infile[iFile],options,lTmp,iFile);
  } else
      if (iFile > 0)  //if line num not ge 0, then if iFile gt 0, then set default.
      body[iFile-1].dTCore = options->dDefault;
}


/* Initiatlize Input Options */

void InitializeOptionsThermint(OPTIONS *options,fnReadOption fnRead[]) {
  int iOpt,iFile;

  /* TMan */
  sprintf(options[OPT_TMAN].cName,"dTMan");
  sprintf(options[OPT_TMAN].cDescr,"Initial Mantle Temperature");
  sprintf(options[OPT_TMAN].cDefault,"Default=3000");
  options[OPT_TMAN].iType = 2;
  options[OPT_TMAN].iMultiFile = 1;
  options[OPT_TMAN].dNeg = 3000.0d;  //Not sure about this??
  options[OPT_TMAN].dDefault = 3000.0d; 
  sprintf(options[OPT_TMAN].cNeg,"Default=3000");
  fnRead[OPT_TMAN] = &ReadTMan;
   /* TCore */
  sprintf(options[OPT_TCORE].cName,"dTCore");
  sprintf(options[OPT_TCORE].cDescr,"Initial Core Temperature");
  sprintf(options[OPT_TCORE].cDefault,"Default=6000");
  options[OPT_TCORE].iType = 2;
  options[OPT_TCORE].iMultiFile = 1;
  options[OPT_TCORE].dNeg = 6000.0d;  //Not sure about this??
  options[OPT_TCORE].dDefault = 6000.0d; 
  sprintf(options[OPT_TCORE].cNeg,"Default=6000");
  fnRead[OPT_TCORE] = &ReadTCore;

}

void ReadOptionsThermint(BODY *body,CONTROL *control,FILES *files,OPTIONS *options,SYSTEM *system,fnReadOption fnRead[],int iBody) {
  int iOpt;

  for (iOpt=OPTSTARTTHERMINT;iOpt<OPTENDTHERMINT;iOpt++) {
    if (options[iOpt].iType != -1) 
      fnRead[iOpt](body,control,files,&options[iOpt],system,iBody+1);
  }
}
    
/******************* Verify THERMINT ******************/

void VerifyRotationThermint(BODY *body,CONTROL *control,OPTIONS *options,char cFile[],int iBody) {
  /* Nothing */
}

/* Is this necessary? */
void AssignTMan(BODY *body,OPTIONS *options,double dAge,int iBody) {
    /* Mantle */
    /*    if (options[OPT_TMAN].iLine[iBody+1] >= 0) {
	body[iBody].d40KNumMan=body[iBody].d40KMassMan/(MASS40K);
	printf("40KMassMan set, body[iBody].d40KNumMan=%e, ENUMMAN40K=%e\n",body[iBody].d40KNumMan,ENUMMAN40K);
    }
    body[iBody].dTMan = fd40KConstant(body[iBody].d40KNumMan,dAge);  //Get the constant given num and age.
    */
}


void VerifyTMan(BODY *body,OPTIONS *options,UPDATE *update,double dAge,fnUpdateVariable ***fnUpdate,int iBody) {
    //  AssignTMan(body,options,dAge,iBody);
    /* Mantle */
    update[iBody].iaType[update[iBody].iTMan][0] = 1; //iaType=0 for prescribed evolution, =1 for differential evolution (normal)
    update[iBody].iNumBodies[update[iBody].iTMan][0]=1;
    update[iBody].iaBody[update[iBody].iTMan][0] = malloc(update[iBody].iNumBodies[update[iBody].iTMan][0]*sizeof(int)); //iaBody is the number of bodies that are affected by this variable.
    update[iBody].iaBody[update[iBody].iTMan][0][0]=iBody;
    update[iBody].pdTDotMan = &update[iBody].daDerivProc[update[iBody].iTMan][0];
    fnUpdate[iBody][update[iBody].iTMan][0] = &fdTDotMan;
}

void VerifyTCore(BODY *body,OPTIONS *options,UPDATE *update,double dAge,fnUpdateVariable ***fnUpdate,int iBody) {
    //  AssignTCore(body,options,dAge,iBody);
    /* Core */
    update[iBody].iaType[update[iBody].iTCore][0] = 1; //iaType=0 for prescribed evolution, =1 for differential evolution (normal)
    update[iBody].iNumBodies[update[iBody].iTCore][0]=1;
    update[iBody].iaBody[update[iBody].iTCore][0] = malloc(update[iBody].iNumBodies[update[iBody].iTCore][0]*sizeof(int)); //iaBody is the number of bodies that are affected by this variable.
    update[iBody].iaBody[update[iBody].iTCore][0][0]=iBody;
    update[iBody].pdTDotCore = &update[iBody].daDerivProc[update[iBody].iTCore][0];
    fnUpdate[iBody][update[iBody].iTCore][0] = &fdTDotCore;
}


/* Auxiliary Properties */
void fnPropertiesThermint(BODY *body,UPDATE *update,int iBody) {
  /* Scalar Properties */
  body[iBody].dTUMan=fdTUMan(body,iBody);
  body[iBody].dTLMan=fdTLMan(body,iBody);
  body[iBody].dTCMB=fdTCMB(body,iBody);
  body[iBody].dTJumpUMan=fdTJumpUMan(body,iBody);
  body[iBody].dTJumpLMan=fdTJumpLMan(body,iBody);
  body[iBody].dViscUMan=fdViscUMan(body,iBody);
  body[iBody].dViscLMan=fdViscLMan(body,iBody);
  body[iBody].dBLUMan=fdBLUMan(body,iBody);
  body[iBody].dBLLMan=fdBLLMan(body,iBody);
  /* Heat Flows */
  /* Mantle */
  body[iBody].dHfluxUMan=fdHfluxUMan(body,iBody);
  body[iBody].dHfluxLMan=fdHfluxLMan(body,iBody);
  body[iBody].dHfluxCMB=fdHfluxCMB(body,iBody);
  body[iBody].dHflowUMan=fdHflowUMan(body,iBody);
  body[iBody].dHflowLMan=fdHflowLMan(body,iBody);
  body[iBody].dHflowCMB=fdHflowCMB(body,iBody);
  /* Core */

    //body[iBody].dTsolUMan=fdTsolUMan(body,iBody);
    //body[iBody].dTliqUMan=fdTliqUMan(body,iBody);
    //body[iBody].dTsolLMan=fdTsolLMan(body,iBody);
    //body[iBody].dTliqLMan=fdTliqLMan(body,iBody);
    //body[iBody].dFMeltUMan=fdFMeltUMan(body,iBody);
    //body[iBody].dFMeltLMan=fdFMeltLMan(body,iBody);
    //body[iBody].dShmodMan=fdShmodMan(body,iBody);
    //body[iBody].dShmodMan=fdShmodMan(body,iBody);
    //body[iBody].dImLove2Man=fdImLove2Man(body,iBody);
    //body[iBody].dLove2Man=fdLove2Man(body,iBody);

}

void fnForceBehaviorThermint(BODY *body,EVOLVE *evolve,IO *io,int iBody,int iModule) {
  if (body[iBody].dTMan < 0.5)
    body[iBody].dTMan = 0;
  if (body[iBody].dTCore < 0.5)
    body[iBody].dTCore = 0;
}

void VerifyThermint(BODY *body,CONTROL *control,FILES *files,OPTIONS *options,OUTPUT *output,SYSTEM *system,UPDATE *update,fnUpdateVariable ***fnUpdate,int iBody,int iModule) {
  VerifyTMan(body,options,update,body[iBody].dAge,fnUpdate,iBody);  //Verify Man.
  VerifyTCore(body,options,update,body[iBody].dAge,fnUpdate,iBody);  //Verify Core.

  control->fnForceBehavior[iBody][iModule] = &fnForceBehaviorThermint;
  control->Evolve.fnAuxProps[iBody][iModule] = &fnPropertiesThermint;
  control->Evolve.fnBodyCopy[iBody][iModule] = &BodyCopyThermint;
  //  output[OUT_TDOTMAN].fnOutput[iBody][iModule] = &fdTDotMan;
}


void InitializeModuleThermint(CONTROL *control,MODULE *module) {
  /* Anything Here? */
}

/**************** RADHEAT update ****************/

void InitializeUpdateThermint(BODY *body,UPDATE *update,int iBody) {
  /* Initially allow all radiogenic heat sources to be present. If any are 0, 
     or < dMinRadPower, they will me removed from update[iBody] in 
     ForceBehavior.
  */
  if (body[iBody].dTMan > 0) {
    update[iBody].iNumVars++;
    update[iBody].iNumTMan++;  //Why is iNumTMan incremented here and below?
  }
  if (body[iBody].dTCore > 0) {
    update[iBody].iNumVars++;
    update[iBody].iNumTCore++;  
  }
}

void FinalizeUpdateTManThermint(BODY *body,UPDATE*update,int *iEqn,int iVar,int iBody) {
  update[iBody].iaModule[iVar][*iEqn] = TMAN;
  update[iBody].iNumTMan = (*iEqn)++;
}

void FinalizeUpdateTCoreThermint(BODY *body,UPDATE*update,int *iEqn,int iVar,int iBody) {
  update[iBody].iaModule[iVar][*iEqn] = TCORE;
  update[iBody].iNumTCore = (*iEqn)++;
}


/***************** RADHEAT Halts *****************/

/* Minimum TMan */
int fbHaltMinTMan(BODY *body,EVOLVE *evolve,HALT *halt,IO *io,UPDATE *update,int iBody) {
  if (body[iBody].dTMan < halt->dMinTMan) {
    if (io->iVerbose >= VERBPROG) {
      printf("HALT: %s's TMan =  ",body[iBody].cName);
      fprintd(stdout,body[iBody].dTMan,io->iSciNot,io->iDigits);
      printf(" < ");
      fprintd(stdout,halt->dMinTMan,io->iSciNot,io->iDigits);
      printf(".\n");
    }
    return 1;
  }
  return 0;
}

int fbHaltMinTCore(BODY *body,EVOLVE *evolve,HALT *halt,IO *io,UPDATE *update,int iBody) {
  if (body[iBody].dTCore < halt->dMinTCore) {
    if (io->iVerbose >= VERBPROG) {
      printf("HALT: %s's TCore =  ",body[iBody].cName);
      fprintd(stdout,body[iBody].dTCore,io->iSciNot,io->iDigits);
      printf(" < ");
      fprintd(stdout,halt->dMinTCore,io->iSciNot,io->iDigits);
      printf(".\n");
    }
    return 1;
  }
  return 0;
}        

void CountHaltsThermint(HALT *halt,int *iHalt) {
  if (halt->dMinTMan >= 0)
    (iHalt)++;
  if (halt->dMinTCore >= 0)
    (iHalt)++;
}

void VerifyHaltThermint(BODY *body,CONTROL *control,OPTIONS *options,int iBody,int *iHalt) {
  if (control->Halt[iBody].dMinTMan > 0)
    control->fnHalt[iBody][(*iHalt)++] = &fbHaltMinTMan;
  if (control->Halt[iBody].dMinTCore > 0)
    control->fnHalt[iBody][(*iHalt)++] = &fbHaltMinTCore;
}

/************* RADHEAT Outputs ******************/

void HelpOutputThermint(OUTPUT *output) {
  int iOut;

  printf("\n ------ THERMINT output ------\n");
  for (iOut=OUTSTARTTHERMINT;iOut<OUTENDTHERMINT;iOut++) 
    WriteHelpOutput(&output[iOut]);
}

/* NOTE: If you write a new Write subroutine here you need to add the associate 
   block of initialization in InitializeOutputThermint below */

void WriteTMan(BODY *body,CONTROL *control,OUTPUT *output,SYSTEM *system,UNITS *units,UPDATE *update,int iBody,double *dTmp,char cUnit[]) {
  /* Get TMan */
  *dTmp = body[iBody].dTMan;
  if (output->bDoNeg[iBody]) {
    *dTmp *= output->dNeg;
    strcpy(cUnit,output->cNeg);
  } else { 
      /*      *dTmp /= fdUnitsTemp(body[iBody].dTman,0,units->iTemp);  //set "iOldType" to 0, second input var, arbitarily.
    fsUnitsTemp(units->iTemp,cUnit);
      */
  }
}
void WriteTUMan(BODY *body,CONTROL *control,OUTPUT *output,SYSTEM *system,UNITS *units,UPDATE *update,int iBody,double *dTmp,char cUnit[]) {
  /* Get TUMan */
    *dTmp = body[iBody].dTUMan;
  if (output->bDoNeg[iBody]) {
    *dTmp *= output->dNeg;
    strcpy(cUnit,output->cNeg);
  } else { }
}
void WriteTLMan(BODY *body,CONTROL *control,OUTPUT *output,SYSTEM *system,UNITS *units,UPDATE *update,int iBody,double *dTmp,char cUnit[]) {
  /* Get TLMan */
    *dTmp = body[iBody].dTLMan;
  if (output->bDoNeg[iBody]) {
    *dTmp *= output->dNeg;
    strcpy(cUnit,output->cNeg);
  } else { }
}
void WriteTJumpUMan(BODY *body,CONTROL *control,OUTPUT *output,SYSTEM *system,UNITS *units,UPDATE *update,int iBody,double *dTmp,char cUnit[]) {
  /* Get TLMan */
    *dTmp = body[iBody].dTJumpUMan;
  if (output->bDoNeg[iBody]) {
    *dTmp *= output->dNeg;
    strcpy(cUnit,output->cNeg);
  } else { }
}
void WriteTJumpLMan(BODY *body,CONTROL *control,OUTPUT *output,SYSTEM *system,UNITS *units,UPDATE *update,int iBody,double *dTmp,char cUnit[]) {
  /* Get TLMan */
    *dTmp = body[iBody].dTJumpLMan;
  if (output->bDoNeg[iBody]) {
    *dTmp *= output->dNeg;
    strcpy(cUnit,output->cNeg);
  } else { }
}

void WriteTCMB(BODY *body,CONTROL *control,OUTPUT *output,SYSTEM *system,UNITS *units,UPDATE *update,int iBody,double *dTmp,char cUnit[]) {
  /* Get TCore */
  *dTmp = body[iBody].dTCMB;
  if (output->bDoNeg[iBody]) {
    *dTmp *= output->dNeg;
    strcpy(cUnit,output->cNeg);
  } else { }
}
void WriteTCore(BODY *body,CONTROL *control,OUTPUT *output,SYSTEM *system,UNITS *units,UPDATE *update,int iBody,double *dTmp,char cUnit[]) {
  /* Get TCore */
  *dTmp = body[iBody].dTCore;
  if (output->bDoNeg[iBody]) {
    *dTmp *= output->dNeg;
    strcpy(cUnit,output->cNeg);
  } else { }
}

void WriteViscUMan(BODY *body,CONTROL *control,OUTPUT *output,SYSTEM *system,UNITS *units,UPDATE *update,int iBody,double *dTmp,char cUnit[]) {
  /* Get TUMan */
    *dTmp = body[iBody].dViscUMan;
  if (output->bDoNeg[iBody]) {
    *dTmp *= output->dNeg;
    strcpy(cUnit,output->cNeg);
  } else { }
}
void WriteViscLMan(BODY *body,CONTROL *control,OUTPUT *output,SYSTEM *system,UNITS *units,UPDATE *update,int iBody,double *dTmp,char cUnit[]) {
  /* Get TLMan */
    *dTmp = body[iBody].dViscLMan;
  if (output->bDoNeg[iBody]) {
    *dTmp *= output->dNeg;
    strcpy(cUnit,output->cNeg);
  } else { }
}
void WriteBLUMan(BODY *body,CONTROL *control,OUTPUT *output,SYSTEM *system,UNITS *units,UPDATE *update,int iBody,double *dTmp,char cUnit[]) {
    *dTmp = body[iBody].dBLUMan;
  if (output->bDoNeg[iBody]) {
    *dTmp *= output->dNeg;
    strcpy(cUnit,output->cNeg);
  } else { }
}
void WriteBLLMan(BODY *body,CONTROL *control,OUTPUT *output,SYSTEM *system,UNITS *units,UPDATE *update,int iBody,double *dTmp,char cUnit[]) {
    *dTmp = body[iBody].dBLLMan;
  if (output->bDoNeg[iBody]) {
    *dTmp *= output->dNeg;
    strcpy(cUnit,output->cNeg);
  } else { }
}

/* Heat Flows/Fluxes */
void WriteHfluxUMan(BODY *body,CONTROL *control,OUTPUT *output,SYSTEM *system,UNITS *units,UPDATE *update,int iBody,double *dTmp,char cUnit[]) {
    *dTmp = body[iBody].dHfluxUMan;
  if (output->bDoNeg[iBody]) {
    *dTmp *= output->dNeg;
    strcpy(cUnit,output->cNeg);
  } else { }
}
void WriteHfluxLMan(BODY *body,CONTROL *control,OUTPUT *output,SYSTEM *system,UNITS *units,UPDATE *update,int iBody,double *dTmp,char cUnit[]) {
    *dTmp = body[iBody].dHfluxLMan;
  if (output->bDoNeg[iBody]) {
    *dTmp *= output->dNeg;
    strcpy(cUnit,output->cNeg);
  } else { }
}
void WriteHfluxCMB(BODY *body,CONTROL *control,OUTPUT *output,SYSTEM *system,UNITS *units,UPDATE *update,int iBody,double *dTmp,char cUnit[]) {
    *dTmp = body[iBody].dHfluxCMB;
  if (output->bDoNeg[iBody]) {
    *dTmp *= output->dNeg;
    strcpy(cUnit,output->cNeg);
  } else { }
}
void WriteHflowUMan(BODY *body,CONTROL *control,OUTPUT *output,SYSTEM *system,UNITS *units,UPDATE *update,int iBody,double *dTmp,char cUnit[]) {
    *dTmp = body[iBody].dHflowUMan;
  if (output->bDoNeg[iBody]) {
    *dTmp *= output->dNeg;
    strcpy(cUnit,output->cNeg);
  } else { }
}
void WriteHflowLMan(BODY *body,CONTROL *control,OUTPUT *output,SYSTEM *system,UNITS *units,UPDATE *update,int iBody,double *dTmp,char cUnit[]) {
    *dTmp = body[iBody].dHflowLMan;
  if (output->bDoNeg[iBody]) {
    *dTmp *= output->dNeg;
    strcpy(cUnit,output->cNeg);
  } else { }
}
void WriteHflowCMB(BODY *body,CONTROL *control,OUTPUT *output,SYSTEM *system,UNITS *units,UPDATE *update,int iBody,double *dTmp,char cUnit[]) {
    *dTmp = body[iBody].dHflowCMB;
  if (output->bDoNeg[iBody]) {
    *dTmp *= output->dNeg;
    strcpy(cUnit,output->cNeg);
  } else { }
}


void WriteTDotMan(BODY *body,CONTROL *control,OUTPUT *output,SYSTEM *system,UNITS *units,UPDATE *update,int iBody,double *dTmp,char cUnit[]) {
  /* Get TDotMan */
  *dTmp = (*(update[iBody].pdTDotMan));
  if (output->bDoNeg[iBody]) {
    *dTmp *= output->dNeg;
    strcpy(cUnit,output->cNeg);
  } else {
      /*
      *dTmp /= fdUnitsTemp(body[iBody].dTman,0,units->iTemp)/fdUnitsTime(units->iTime);
      fsUnitsTempRate(units->iTemp,cUnit);  // only handles Temp/s, need to add yr and Gyr options.
      */
  }
}

void WriteTDotCore(BODY *body,CONTROL *control,OUTPUT *output,SYSTEM *system,UNITS *units,UPDATE *update,int iBody,double *dTmp,char cUnit[]) {
  /* Get TDotCore */
  *dTmp = (*(update[iBody].pdTDotCore));
  if (output->bDoNeg[iBody]) {
    *dTmp *= output->dNeg;
    strcpy(cUnit,output->cNeg);
  } else {
      /*
      *dTmp /= fdUnitsTemp(body[iBody].dTman,0,units->iTemp)/fdUnitsTime(units->iTime);
      fsUnitsTempRate(units->iTemp,cUnit);  // only handles Temp/s, need to add yr and Gyr options.
      */
  }
}

void InitializeOutputThermint(OUTPUT *output,fnWriteOutput fnWrite[]) {
  sprintf(output[OUT_TMAN].cName,"TMan");
  sprintf(output[OUT_TMAN].cDescr,"Mantle Temperature");
  sprintf(output[OUT_TMAN].cNeg,"K");
  output[OUT_TMAN].bNeg = 1;
  output[OUT_TMAN].dNeg = 1; // default units are K. 
  output[OUT_TMAN].iNum = 1;
  fnWrite[OUT_TMAN] = &WriteTMan;

  sprintf(output[OUT_TUMAN].cName,"TUMan");
  sprintf(output[OUT_TUMAN].cDescr,"Upper Mantle Temperature");
  sprintf(output[OUT_TUMAN].cNeg,"K");
  output[OUT_TUMAN].bNeg = 1;
  output[OUT_TUMAN].dNeg = 1; // default units are K. 
  output[OUT_TUMAN].iNum = 1;
  fnWrite[OUT_TUMAN] = &WriteTUMan;

  sprintf(output[OUT_TLMAN].cName,"TLMan");
  sprintf(output[OUT_TLMAN].cDescr,"Lower Mantle Temperature");
  sprintf(output[OUT_TLMAN].cNeg,"K");
  output[OUT_TLMAN].bNeg = 1;
  output[OUT_TLMAN].dNeg = 1; // default units are K. 
  output[OUT_TLMAN].iNum = 1;
  fnWrite[OUT_TLMAN] = &WriteTLMan;
  
  sprintf(output[OUT_TJUMPUMAN].cName,"TJumpUMan");
  sprintf(output[OUT_TJUMPUMAN].cDescr,"Upper Mantle Temperature Jump");
  sprintf(output[OUT_TJUMPUMAN].cNeg,"K");
  output[OUT_TJUMPUMAN].bNeg = 1;
  output[OUT_TJUMPUMAN].dNeg = 1; // default units are K. 
  output[OUT_TJUMPUMAN].iNum = 1;
  fnWrite[OUT_TJUMPUMAN] = &WriteTJumpUMan;

  sprintf(output[OUT_TJUMPLMAN].cName,"TJumpLMan");
  sprintf(output[OUT_TJUMPLMAN].cDescr,"Lower Mantle Temperature Jump");
  sprintf(output[OUT_TJUMPLMAN].cNeg,"K");
  output[OUT_TJUMPLMAN].bNeg = 1;
  output[OUT_TJUMPLMAN].dNeg = 1; // default units are K. 
  output[OUT_TJUMPLMAN].iNum = 1;
  fnWrite[OUT_TJUMPLMAN] = &WriteTJumpLMan;
  
  sprintf(output[OUT_TCMB].cName,"TCMB");
  sprintf(output[OUT_TCMB].cDescr,"CMB Temperature");
  sprintf(output[OUT_TCMB].cNeg,"K");
  output[OUT_TCMB].bNeg = 1;
  output[OUT_TCMB].dNeg = 1; // default units are K. 
  output[OUT_TCMB].iNum = 1;
  fnWrite[OUT_TCMB] = &WriteTCMB;

  sprintf(output[OUT_TCORE].cName,"TCore");
  sprintf(output[OUT_TCORE].cDescr,"Core Temperature");
  sprintf(output[OUT_TCORE].cNeg,"K");
  output[OUT_TCORE].bNeg = 1;
  output[OUT_TCORE].dNeg = 1; // default units are K. 
  output[OUT_TCORE].iNum = 1;
  fnWrite[OUT_TCORE] = &WriteTCore;

  sprintf(output[OUT_VISCUMAN].cName,"ViscUMan");
  sprintf(output[OUT_VISCUMAN].cDescr,"Upper Mantle Viscosity");
  sprintf(output[OUT_VISCUMAN].cNeg,"m^2/s");
  output[OUT_VISCUMAN].bNeg = 1;
  output[OUT_VISCUMAN].dNeg = 1; 
  output[OUT_VISCUMAN].iNum = 1;
  fnWrite[OUT_VISCUMAN] = &WriteViscUMan;

  sprintf(output[OUT_VISCLMAN].cName,"ViscLMan");
  sprintf(output[OUT_VISCLMAN].cDescr,"Lower Mantle Viscosity");
  sprintf(output[OUT_VISCLMAN].cNeg,"m^2/s");
  output[OUT_VISCLMAN].bNeg = 1;
  output[OUT_VISCLMAN].dNeg = 1; 
  output[OUT_VISCLMAN].iNum = 1;
  fnWrite[OUT_VISCLMAN] = &WriteViscLMan;

  sprintf(output[OUT_BLUMAN].cName,"BLUMan");
  sprintf(output[OUT_BLUMAN].cDescr,"Boundary Layer Thickness Upper Mantle");
  sprintf(output[OUT_BLUMAN].cNeg,"km");
  output[OUT_BLUMAN].bNeg = 1;
  output[OUT_BLUMAN].dNeg = 1;  //KM; 
  output[OUT_BLUMAN].iNum = 1;
  fnWrite[OUT_BLUMAN] = &WriteBLUMan;

  sprintf(output[OUT_BLLMAN].cName,"BLLMan");
  sprintf(output[OUT_BLLMAN].cDescr,"Boundary Layer Thickness Lower Mantle");
  sprintf(output[OUT_BLLMAN].cNeg,"km");
  output[OUT_BLLMAN].bNeg = 1;
  output[OUT_BLLMAN].dNeg = 1; 
  output[OUT_BLLMAN].iNum = 1;
  fnWrite[OUT_BLLMAN] = &WriteBLLMan;

  /* Heat Fluxes/Flows */
  /* HFluxUMan */
  sprintf(output[OUT_HFLUXUMAN].cName,"HfluxUMan");
  sprintf(output[OUT_HFLUXUMAN].cDescr,"Heat Flux Upper Mantle");
  sprintf(output[OUT_HFLUXUMAN].cNeg,"W/m^2");
  output[OUT_HFLUXUMAN].bNeg = 1;
  output[OUT_HFLUXUMAN].dNeg = 1;  //KM; 
  output[OUT_HFLUXUMAN].iNum = 1;
  fnWrite[OUT_HFLUXUMAN] = &WriteHfluxUMan;
  /* HFluxLMan */
  sprintf(output[OUT_HFLUXLMAN].cName,"HfluxLMan");
  sprintf(output[OUT_HFLUXLMAN].cDescr,"Heat Flux Lower Mantle");
  sprintf(output[OUT_HFLUXLMAN].cNeg,"W/m^2");
  output[OUT_HFLUXLMAN].bNeg = 1;
  output[OUT_HFLUXLMAN].dNeg = 1;
  output[OUT_HFLUXLMAN].iNum = 1;
  fnWrite[OUT_HFLUXLMAN] = &WriteHfluxLMan;
  /* HFluxCMB */
  sprintf(output[OUT_HFLUXCMB].cName,"HfluxCMB");
  sprintf(output[OUT_HFLUXCMB].cDescr,"Heat Flux Core-Mantle Boundary");
  sprintf(output[OUT_HFLUXCMB].cNeg,"W/m^2");
  output[OUT_HFLUXCMB].bNeg = 1;
  output[OUT_HFLUXCMB].dNeg = 1;
  output[OUT_HFLUXCMB].iNum = 1;
  fnWrite[OUT_HFLUXCMB] = &WriteHfluxCMB;
  /* HFlowUMan */
  sprintf(output[OUT_HFLOWUMAN].cName,"HflowUMan");
  sprintf(output[OUT_HFLOWUMAN].cDescr,"Heat Flow Upper Mantle");
  sprintf(output[OUT_HFLOWUMAN].cNeg,"W");
  output[OUT_HFLOWUMAN].bNeg = 1;
  output[OUT_HFLOWUMAN].dNeg = 1;
  output[OUT_HFLOWUMAN].iNum = 1;
  fnWrite[OUT_HFLOWUMAN] = &WriteHflowUMan;
  /* HFlowLMan */
  sprintf(output[OUT_HFLOWLMAN].cName,"HflowLMan");
  sprintf(output[OUT_HFLOWLMAN].cDescr,"Heat Flow Lower Mantle");
  sprintf(output[OUT_HFLOWLMAN].cNeg,"W");
  output[OUT_HFLOWLMAN].bNeg = 1;
  output[OUT_HFLOWLMAN].dNeg = 1;
  output[OUT_HFLOWLMAN].iNum = 1;
  fnWrite[OUT_HFLOWLMAN] = &WriteHflowLMan;
  /* HFlowCMB */
  sprintf(output[OUT_HFLOWCMB].cName,"HflowCMB");
  sprintf(output[OUT_HFLOWCMB].cDescr,"Heat Flow Core-Mantle Boundary");
  sprintf(output[OUT_HFLOWCMB].cNeg,"W");
  output[OUT_HFLOWCMB].bNeg = 1;
  output[OUT_HFLOWCMB].dNeg = 1;
  output[OUT_HFLOWCMB].iNum = 1;
  fnWrite[OUT_HFLOWCMB] = &WriteHflowCMB;
  /* TDotMan */
  sprintf(output[OUT_TDOTMAN].cName,"TDotMan");
  sprintf(output[OUT_TDOTMAN].cDescr,"Change in Mantle Temperature");
  sprintf(output[OUT_TDOTMAN].cNeg,"K/s");
  output[OUT_TDOTMAN].bNeg = 1;
  output[OUT_TDOTMAN].dNeg = 1; // default units are K. 
  output[OUT_TDOTMAN].iNum = 1;
  fnWrite[OUT_TDOTMAN] = &WriteTDotMan;
  /* TDotCore */
  sprintf(output[OUT_TDOTCORE].cName,"TDotCore");
  sprintf(output[OUT_TDOTCORE].cDescr,"Change in Core Temperature");
  sprintf(output[OUT_TDOTCORE].cNeg,"K/s");
  output[OUT_TDOTCORE].bNeg = 1;
  output[OUT_TDOTCORE].dNeg = 1; // default units are K. 
  output[OUT_TDOTCORE].iNum = 1;
  fnWrite[OUT_TDOTCORE] = &WriteTDotCore;
}

void FinalizeOutputFunctionThermint(OUTPUT *output,int iBody,int iModule) {
  //  output[OUT_TDOTMAN].fnOutput[iBody][iModule] = &fdTDotMan;
    output[OUT_SURFENFLUX].fnOutput[iBody][iModule] = &fdSurfEnFluxRadheat; //This is need to print the global var to log.  Needs to be fixed.
}

/************ THERMINT Logging Functions **************/

void LogOptionsThermint(CONTROL *control, FILE *fp) {
  /* Anything here?
  fprintf(fp,"-------- RADHEAT Options -----\n\n");
  */
}

//PED: this would be for global rad heat parameters, but this is blank bc rad is only relevant to each individual body.
void LogThermint(BODY *body,CONTROL *control,OUTPUT *output,SYSTEM *system,UPDATE *update,fnWriteOutput fnWrite[],FILE *fp) {
  /* Anything here? 
  int iOut;
  fprintf(fp,"\n----- RADHEAT PARAMETERS ------\n");
  for (iOut=OUTSTARTRADHEAT;iOut<OUTBODYSTARTRADHEAT;iOut++) {
    if (output[iOut].iNum > 0)
      WriteLogEntry(control,output[iOut],body,system,fnWrite[iOut],fp,update,0);
  }
  */
}

void LogBodyThermint(BODY *body,CONTROL *control,OUTPUT *output,SYSTEM *system,UPDATE *update,fnWriteOutput fnWrite[],FILE *fp,int iBody) {
  int iOut;

  fprintf(fp,"----- THERMINT PARAMETERS (%s)------\n",body[iBody].cName);
  for (iOut=OUTSTARTTHERMINT;iOut<OUTENDTHERMINT;iOut++) {
    if (output[iOut].iNum > 0) 
      WriteLogEntry(body,control,&output[iOut],system,update,fnWrite[iOut],fp,iBody);
  }
  /* Write out some global constants. */
  fprintf(fp,"EMASS=%e EMASSMAN=%e ERMAN=%e ERCORE=%e EDMAN=%e EVOL=%e EVOLCORE=%e EVOLMAN=%e\n",EMASS,EMASSMAN,ERMAN,ERCORE,EDMAN,EVOL,EVOLCORE,EVOLMAN);
  fprintf(fp,"EDENS=%e EDENSMAN=%e EDENSCORE=%e EDENSOC=%e EDENSIC=%e\n",EDENS,EDENSMAN,EDENSCORE,EDENSOC,EDENSIC);
  fprintf(fp,"THERMEXPANMAN=%e THERMCONDUMAN=%e THERMCONDLMAN=%e THERMDIFFUMAN=%e cube(EDMAN)=%e\n",THERMEXPANMAN,THERMCONDUMAN,THERMCONDLMAN,THERMDIFFUMAN,cube(EDMAN));
}

void AddModuleThermint(MODULE *module,int iBody,int iModule) {

  module->iaModule[iBody][iModule] = THERMINT;

  module->fnInitializeControl[iBody][iModule] = &InitializeControlThermint;
  module->fnInitializeUpdateTmpBody[iBody][iModule] = &InitializeUpdateTmpBodyThermint;

  module->fnCountHalts[iBody][iModule] = &CountHaltsRadHeat;
  module->fnReadOptions[iBody][iModule] = &ReadOptionsThermint;
  module->fnLogBody[iBody][iModule] = &LogBodyThermint;
  module->fnVerify[iBody][iModule] = &VerifyThermint;
  module->fnVerifyHalt[iBody][iModule] = &VerifyHaltThermint;
  module->fnVerifyRotation[iBody][iModule] = &VerifyRotationThermint;
  
  module->fnInitializeBody[iBody][iModule] = &InitializeBodyThermint;
  module->fnInitializeUpdate[iBody][iModule] = &InitializeUpdateThermint;

    // NEED TO ADD THERMINT VARIABLES HERE??
  module->fnFinalizeUpdateTMan[iBody][iModule] = &FinalizeUpdateTManThermint;
  module->fnFinalizeUpdateTCore[iBody][iModule] = &FinalizeUpdateTCoreThermint;

  //module->fnIntializeOutputFunction[iBody][iModule] = &InitializeOutputFunctionThermint;
  module->fnFinalizeOutputFunction[iBody][iModule] = &FinalizeOutputFunctionThermint;

}

/************* THERMINT Functions ************/
/* Scalar Properties */
/* Get TUMan */
double fdTUMan(BODY *body,int iBody) {
  return ADJUMPM2UM*body[iBody].dTMan;
}
/* Get TLMan */
double fdTLMan(BODY *body,int iBody) {
    return ADJUMPM2LM*body[iBody].dTMan;
}
/* Get TCMB */
double fdTCMB(BODY *body,int iBody) {
    return ADJUMPC2CMB*body[iBody].dTCore;
}
/* Get TJumpUMan */ 
double fdTJumpUMan(BODY *body,int iBody) {
    return body[iBody].dTUMan-TSURF;
}
/* Get TJumpLMan */
double fdTJumpLMan(BODY *body,int iBody) {
    return body[iBody].dTCMB-body[iBody].dTLMan;
}
/* Get ViscUMan */
double fdViscUMan(BODY *body,int iBody) {
  return VISCREF*exp(ACTVISCMAN/(GASCONSTANT*body[iBody].dTUMan));
}
double fdViscLMan(BODY *body,int iBody) {
  return body[iBody].dViscUMan*VISCJUMPULM;  //this could be switched to be visc(TLMan).
}
/* Get Boundary Layer Thicknesses */
double fdBLUMan(BODY *body,int iBody) {
  return (EDMAN)*pow((RACRIT)*body[iBody].dViscUMan*(THERMDIFFUMAN)/((THERMEXPANMAN)*(GRAVLMAN)*body[iBody].dTJumpLMan*cube(EDMAN)),(CONVEXPON));
}
double fdBLLMan(BODY *body,int iBody) {
  return (EDMAN)*pow((RACRIT)*body[iBody].dViscLMan*(THERMDIFFLMAN)/((THERMEXPANMAN)*(GRAVLMAN)*body[iBody].dTJumpLMan*cube(EDMAN)),(CONVEXPON));
}

/* Heat Fluxes/flows */
double fdHfluxUMan(BODY *body,int iBody) {
  return (THERMCONDUMAN)*body[iBody].dTJumpUMan/body[iBody].dBLUMan;
}
double fdHfluxLMan(BODY *body,int iBody) {
  return (THERMCONDLMAN)*body[iBody].dTJumpLMan/body[iBody].dBLLMan;
}
double fdHfluxCMB(BODY *body,int iBody) {
  return fdHfluxLMan(body,iBody);
}
double fdHflowUMan(BODY *body,int iBody) {
  return (AREASURF)*fdHfluxUMan(body,iBody);
}
double fdHflowLMan(BODY *body,int iBody) {
  return (AREACMB)*fdHfluxLMan(body,iBody);
}
double fdHflowCMB(BODY *body,int iBody) {
  return fdHflowLMan(body,iBody);
}

/*** These derivatives are called from the udpate matrix, format is fixed. ***/
/* Get TDotMan */
double fdTDotMan(BODY *body,SYSTEM *system,int *iaBody,int iNumBodies) {
  //return -(100.0/1e9/YEARSEC);   //arbitrary for now.
  //    return body[iBody].dPowRadiogMan;
  int iBody=iaBody[0];   //Is this correct?
  return (body[iBody].dHflowCMB+body[iBody].dPowRadiogMan-body[iBody].dHflowUMan)/((EMASSMAN)*(SPECHEATMAN));
}

/* Get TDotCore */
double fdTDotCore(BODY *body,SYSTEM *system,int *iaBody,int iNumBodies) {
    //return -(100.0/1e9/YEARSEC);   //arbitrary for now.
  int iBody=iaBody[0];   //Is this correct?
  return (-body[iBody].dHflowCMB+body[iBody].dPowRadiogCore)/((EMASSCORE)*(SPECHEATCORE));   //NEED to add IC heat.
}

/* MATH FUNCTIONS */
double cube(double x) {
  return pow(x,3);
}

