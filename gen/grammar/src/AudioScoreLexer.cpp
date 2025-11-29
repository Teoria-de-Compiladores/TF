
// Generated from src/AudioScore.g4 by ANTLR 4.13.1


#include "AudioScoreLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct AudioScoreLexerStaticData final {
  AudioScoreLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  AudioScoreLexerStaticData(const AudioScoreLexerStaticData&) = delete;
  AudioScoreLexerStaticData(AudioScoreLexerStaticData&&) = delete;
  AudioScoreLexerStaticData& operator=(const AudioScoreLexerStaticData&) = delete;
  AudioScoreLexerStaticData& operator=(AudioScoreLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag audioscorelexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
AudioScoreLexerStaticData *audioscorelexerLexerStaticData = nullptr;

void audioscorelexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (audioscorelexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(audioscorelexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<AudioScoreLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "NOTE", "OCTAVE", "DUR", "INT", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'tempo'", "';'", "'rest'"
    },
    std::vector<std::string>{
      "", "", "", "", "NOTE", "OCTAVE", "DUR", "INT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,8,50,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,
  	2,7,7,7,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,3,1,3,3,
  	3,33,8,3,1,4,1,4,1,5,1,5,1,6,4,6,40,8,6,11,6,12,6,41,1,7,4,7,45,8,7,11,
  	7,12,7,46,1,7,1,7,0,0,8,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,1,0,6,1,0,
  	65,71,2,0,35,35,98,98,1,0,48,56,3,0,101,101,104,104,113,113,1,0,48,57,
  	3,0,9,10,13,13,32,32,52,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,
  	0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,1,17,1,0,0,0,3,23,
  	1,0,0,0,5,25,1,0,0,0,7,30,1,0,0,0,9,34,1,0,0,0,11,36,1,0,0,0,13,39,1,
  	0,0,0,15,44,1,0,0,0,17,18,5,116,0,0,18,19,5,101,0,0,19,20,5,109,0,0,20,
  	21,5,112,0,0,21,22,5,111,0,0,22,2,1,0,0,0,23,24,5,59,0,0,24,4,1,0,0,0,
  	25,26,5,114,0,0,26,27,5,101,0,0,27,28,5,115,0,0,28,29,5,116,0,0,29,6,
  	1,0,0,0,30,32,7,0,0,0,31,33,7,1,0,0,32,31,1,0,0,0,32,33,1,0,0,0,33,8,
  	1,0,0,0,34,35,7,2,0,0,35,10,1,0,0,0,36,37,7,3,0,0,37,12,1,0,0,0,38,40,
  	7,4,0,0,39,38,1,0,0,0,40,41,1,0,0,0,41,39,1,0,0,0,41,42,1,0,0,0,42,14,
  	1,0,0,0,43,45,7,5,0,0,44,43,1,0,0,0,45,46,1,0,0,0,46,44,1,0,0,0,46,47,
  	1,0,0,0,47,48,1,0,0,0,48,49,6,7,0,0,49,16,1,0,0,0,4,0,32,41,46,1,6,0,
  	0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  audioscorelexerLexerStaticData = staticData.release();
}

}

AudioScoreLexer::AudioScoreLexer(CharStream *input) : Lexer(input) {
  AudioScoreLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *audioscorelexerLexerStaticData->atn, audioscorelexerLexerStaticData->decisionToDFA, audioscorelexerLexerStaticData->sharedContextCache);
}

AudioScoreLexer::~AudioScoreLexer() {
  delete _interpreter;
}

std::string AudioScoreLexer::getGrammarFileName() const {
  return "AudioScore.g4";
}

const std::vector<std::string>& AudioScoreLexer::getRuleNames() const {
  return audioscorelexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& AudioScoreLexer::getChannelNames() const {
  return audioscorelexerLexerStaticData->channelNames;
}

const std::vector<std::string>& AudioScoreLexer::getModeNames() const {
  return audioscorelexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& AudioScoreLexer::getVocabulary() const {
  return audioscorelexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView AudioScoreLexer::getSerializedATN() const {
  return audioscorelexerLexerStaticData->serializedATN;
}

const atn::ATN& AudioScoreLexer::getATN() const {
  return *audioscorelexerLexerStaticData->atn;
}




void AudioScoreLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  audioscorelexerLexerInitialize();
#else
  ::antlr4::internal::call_once(audioscorelexerLexerOnceFlag, audioscorelexerLexerInitialize);
#endif
}
