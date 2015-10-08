#pragma once

#include <bdatypes.h>

// �A���e�i�ݒ�
struct AntennaParam {
	long Oscillator;		// LNB���g�� (MHz)
	long Tone;				// �g�[���M�� 0 .. off, 1.. on
	long DiSEqC;			// DiSeqC�w��
	AntennaParam(void)
		: Oscillator(-1),
		  Tone(-1),
		  DiSEqC(-1)
	{};
};

// �ϒ������ݒ�f�[�^
struct ModulationMethod {
	ModulationType Modulation;				// �ϒ��^�C�v
	FECMethod InnerFEC;						// �����O���������^�C�v
	BinaryConvolutionCodeRate InnerFECRate;	// ����FEC���[�g
	FECMethod OuterFEC;						// �O���O���������^�C�v
	BinaryConvolutionCodeRate OuterFECRate;	// �O��FEC���[�g
	long SymbolRate;						// �V���{�����[�g
	long BandWidth;							// �ш敝(MHz)
	ModulationMethod(void)
		: Modulation(BDA_MOD_NOT_SET),
		  InnerFEC(BDA_FEC_METHOD_NOT_SET),
		  InnerFECRate(BDA_BCC_RATE_NOT_SET),
		  OuterFEC(BDA_FEC_METHOD_NOT_SET),
		  OuterFECRate(BDA_BCC_RATE_NOT_SET),
		  SymbolRate(-1),
		  BandWidth(-1)
	{};
};

// LockChannel()�Ŏg�p����`���[�j���O�p�����[�^
struct TuningParam {
	long Frequency;						// ���g��(MHz)
	Polarisation Polarisation;			// �M���̕Δg
	const AntennaParam *Antenna;		// �A���e�i�ݒ�f�[�^
	const ModulationMethod *Modulation;	// �ϒ������ݒ�f�[�^
	long ONID;							// �I���W�i���l�b�g���[�NID
	long TSID;							// �g�����X�|�[�g�X�g���[��ID
	long SID;							// �T�[�r�XID
	TuningParam(void)
		: Frequency(-1),
		  Polarisation(BDA_POLARISATION_NOT_SET),
		  Antenna(NULL),
		  Modulation(NULL),
		  ONID(-1),
		  TSID(-1),
		  SID(-1)
	{};
};