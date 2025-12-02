
// Generated from src/AudioScore.g4 by ANTLR 4.13.1


#include "AudioScoreListener.h"
#include "AudioScoreVisitor.h"

#include "AudioScoreParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct AudioScoreParserStaticData final {
  AudioScoreParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  AudioScoreParserStaticData(const AudioScoreParserStaticData&) = delete;
  AudioScoreParserStaticData(AudioScoreParserStaticData&&) = delete;
  AudioScoreParserStaticData& operator=(const AudioScoreParserStaticData&) = delete;
  AudioScoreParserStaticData& operator=(AudioScoreParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag audioscoreParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
AudioScoreParserStaticData *audioscoreParserStaticData = nullptr;

void audioscoreParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (audioscoreParserStaticData != nullptr) {
    return;
  }
#else
  assert(audioscoreParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<AudioScoreParserStaticData>(
    std::vector<std::string>{
      "program", "tempoStmt", "patternDecl", "statement", "loopStmt", "playStmt", 
      "noteStmt", "restStmt"
    },
    std::vector<std::string>{
      "", "'tempo'", "';'", "'pattern'", "'{'", "'}'", "'loop'", "'play'", 
      "'rest'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "NOTE", "DUR", "INT", "ID", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,13,75,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,
  	7,7,1,0,1,0,5,0,19,8,0,10,0,12,0,22,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,2,1,
  	2,1,2,1,2,5,2,34,8,2,10,2,12,2,37,9,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,3,3,52,8,3,1,4,1,4,1,4,1,4,5,4,58,8,4,10,4,12,4,61,
  	9,4,1,4,1,4,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,0,0,8,0,2,4,6,
  	8,10,12,14,0,0,74,0,20,1,0,0,0,2,25,1,0,0,0,4,29,1,0,0,0,6,51,1,0,0,0,
  	8,53,1,0,0,0,10,64,1,0,0,0,12,67,1,0,0,0,14,71,1,0,0,0,16,19,3,4,2,0,
  	17,19,3,6,3,0,18,16,1,0,0,0,18,17,1,0,0,0,19,22,1,0,0,0,20,18,1,0,0,0,
  	20,21,1,0,0,0,21,23,1,0,0,0,22,20,1,0,0,0,23,24,5,0,0,1,24,1,1,0,0,0,
  	25,26,5,1,0,0,26,27,5,11,0,0,27,28,5,2,0,0,28,3,1,0,0,0,29,30,5,3,0,0,
  	30,31,5,12,0,0,31,35,5,4,0,0,32,34,3,6,3,0,33,32,1,0,0,0,34,37,1,0,0,
  	0,35,33,1,0,0,0,35,36,1,0,0,0,36,38,1,0,0,0,37,35,1,0,0,0,38,39,5,5,0,
  	0,39,5,1,0,0,0,40,41,3,12,6,0,41,42,5,2,0,0,42,52,1,0,0,0,43,44,3,14,
  	7,0,44,45,5,2,0,0,45,52,1,0,0,0,46,52,3,2,1,0,47,52,3,8,4,0,48,49,3,10,
  	5,0,49,50,5,2,0,0,50,52,1,0,0,0,51,40,1,0,0,0,51,43,1,0,0,0,51,46,1,0,
  	0,0,51,47,1,0,0,0,51,48,1,0,0,0,52,7,1,0,0,0,53,54,5,6,0,0,54,55,5,11,
  	0,0,55,59,5,4,0,0,56,58,3,6,3,0,57,56,1,0,0,0,58,61,1,0,0,0,59,57,1,0,
  	0,0,59,60,1,0,0,0,60,62,1,0,0,0,61,59,1,0,0,0,62,63,5,5,0,0,63,9,1,0,
  	0,0,64,65,5,7,0,0,65,66,5,12,0,0,66,11,1,0,0,0,67,68,5,9,0,0,68,69,5,
  	11,0,0,69,70,5,10,0,0,70,13,1,0,0,0,71,72,5,8,0,0,72,73,5,10,0,0,73,15,
  	1,0,0,0,5,18,20,35,51,59
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  audioscoreParserStaticData = staticData.release();
}

}

AudioScoreParser::AudioScoreParser(TokenStream *input) : AudioScoreParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

AudioScoreParser::AudioScoreParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  AudioScoreParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *audioscoreParserStaticData->atn, audioscoreParserStaticData->decisionToDFA, audioscoreParserStaticData->sharedContextCache, options);
}

AudioScoreParser::~AudioScoreParser() {
  delete _interpreter;
}

const atn::ATN& AudioScoreParser::getATN() const {
  return *audioscoreParserStaticData->atn;
}

std::string AudioScoreParser::getGrammarFileName() const {
  return "AudioScore.g4";
}

const std::vector<std::string>& AudioScoreParser::getRuleNames() const {
  return audioscoreParserStaticData->ruleNames;
}

const dfa::Vocabulary& AudioScoreParser::getVocabulary() const {
  return audioscoreParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView AudioScoreParser::getSerializedATN() const {
  return audioscoreParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

AudioScoreParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AudioScoreParser::ProgramContext::EOF() {
  return getToken(AudioScoreParser::EOF, 0);
}

std::vector<AudioScoreParser::PatternDeclContext *> AudioScoreParser::ProgramContext::patternDecl() {
  return getRuleContexts<AudioScoreParser::PatternDeclContext>();
}

AudioScoreParser::PatternDeclContext* AudioScoreParser::ProgramContext::patternDecl(size_t i) {
  return getRuleContext<AudioScoreParser::PatternDeclContext>(i);
}

std::vector<AudioScoreParser::StatementContext *> AudioScoreParser::ProgramContext::statement() {
  return getRuleContexts<AudioScoreParser::StatementContext>();
}

AudioScoreParser::StatementContext* AudioScoreParser::ProgramContext::statement(size_t i) {
  return getRuleContext<AudioScoreParser::StatementContext>(i);
}


size_t AudioScoreParser::ProgramContext::getRuleIndex() const {
  return AudioScoreParser::RuleProgram;
}

void AudioScoreParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void AudioScoreParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any AudioScoreParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AudioScoreVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

AudioScoreParser::ProgramContext* AudioScoreParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, AudioScoreParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(20);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 970) != 0)) {
      setState(18);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case AudioScoreParser::T__2: {
          setState(16);
          patternDecl();
          break;
        }

        case AudioScoreParser::T__0:
        case AudioScoreParser::T__5:
        case AudioScoreParser::T__6:
        case AudioScoreParser::T__7:
        case AudioScoreParser::NOTE: {
          setState(17);
          statement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(22);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(23);
    match(AudioScoreParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TempoStmtContext ------------------------------------------------------------------

AudioScoreParser::TempoStmtContext::TempoStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AudioScoreParser::TempoStmtContext::INT() {
  return getToken(AudioScoreParser::INT, 0);
}


size_t AudioScoreParser::TempoStmtContext::getRuleIndex() const {
  return AudioScoreParser::RuleTempoStmt;
}

void AudioScoreParser::TempoStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTempoStmt(this);
}

void AudioScoreParser::TempoStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTempoStmt(this);
}


std::any AudioScoreParser::TempoStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AudioScoreVisitor*>(visitor))
    return parserVisitor->visitTempoStmt(this);
  else
    return visitor->visitChildren(this);
}

AudioScoreParser::TempoStmtContext* AudioScoreParser::tempoStmt() {
  TempoStmtContext *_localctx = _tracker.createInstance<TempoStmtContext>(_ctx, getState());
  enterRule(_localctx, 2, AudioScoreParser::RuleTempoStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(25);
    match(AudioScoreParser::T__0);
    setState(26);
    match(AudioScoreParser::INT);
    setState(27);
    match(AudioScoreParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PatternDeclContext ------------------------------------------------------------------

AudioScoreParser::PatternDeclContext::PatternDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AudioScoreParser::PatternDeclContext::ID() {
  return getToken(AudioScoreParser::ID, 0);
}

std::vector<AudioScoreParser::StatementContext *> AudioScoreParser::PatternDeclContext::statement() {
  return getRuleContexts<AudioScoreParser::StatementContext>();
}

AudioScoreParser::StatementContext* AudioScoreParser::PatternDeclContext::statement(size_t i) {
  return getRuleContext<AudioScoreParser::StatementContext>(i);
}


size_t AudioScoreParser::PatternDeclContext::getRuleIndex() const {
  return AudioScoreParser::RulePatternDecl;
}

void AudioScoreParser::PatternDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPatternDecl(this);
}

void AudioScoreParser::PatternDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPatternDecl(this);
}


std::any AudioScoreParser::PatternDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AudioScoreVisitor*>(visitor))
    return parserVisitor->visitPatternDecl(this);
  else
    return visitor->visitChildren(this);
}

AudioScoreParser::PatternDeclContext* AudioScoreParser::patternDecl() {
  PatternDeclContext *_localctx = _tracker.createInstance<PatternDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, AudioScoreParser::RulePatternDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29);
    match(AudioScoreParser::T__2);
    setState(30);
    match(AudioScoreParser::ID);
    setState(31);
    match(AudioScoreParser::T__3);
    setState(35);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 962) != 0)) {
      setState(32);
      statement();
      setState(37);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(38);
    match(AudioScoreParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

AudioScoreParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AudioScoreParser::NoteStmtContext* AudioScoreParser::StatementContext::noteStmt() {
  return getRuleContext<AudioScoreParser::NoteStmtContext>(0);
}

AudioScoreParser::RestStmtContext* AudioScoreParser::StatementContext::restStmt() {
  return getRuleContext<AudioScoreParser::RestStmtContext>(0);
}

AudioScoreParser::TempoStmtContext* AudioScoreParser::StatementContext::tempoStmt() {
  return getRuleContext<AudioScoreParser::TempoStmtContext>(0);
}

AudioScoreParser::LoopStmtContext* AudioScoreParser::StatementContext::loopStmt() {
  return getRuleContext<AudioScoreParser::LoopStmtContext>(0);
}

AudioScoreParser::PlayStmtContext* AudioScoreParser::StatementContext::playStmt() {
  return getRuleContext<AudioScoreParser::PlayStmtContext>(0);
}


size_t AudioScoreParser::StatementContext::getRuleIndex() const {
  return AudioScoreParser::RuleStatement;
}

void AudioScoreParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void AudioScoreParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any AudioScoreParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AudioScoreVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

AudioScoreParser::StatementContext* AudioScoreParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 6, AudioScoreParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(51);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AudioScoreParser::NOTE: {
        enterOuterAlt(_localctx, 1);
        setState(40);
        noteStmt();
        setState(41);
        match(AudioScoreParser::T__1);
        break;
      }

      case AudioScoreParser::T__7: {
        enterOuterAlt(_localctx, 2);
        setState(43);
        restStmt();
        setState(44);
        match(AudioScoreParser::T__1);
        break;
      }

      case AudioScoreParser::T__0: {
        enterOuterAlt(_localctx, 3);
        setState(46);
        tempoStmt();
        break;
      }

      case AudioScoreParser::T__5: {
        enterOuterAlt(_localctx, 4);
        setState(47);
        loopStmt();
        break;
      }

      case AudioScoreParser::T__6: {
        enterOuterAlt(_localctx, 5);
        setState(48);
        playStmt();
        setState(49);
        match(AudioScoreParser::T__1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopStmtContext ------------------------------------------------------------------

AudioScoreParser::LoopStmtContext::LoopStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AudioScoreParser::LoopStmtContext::INT() {
  return getToken(AudioScoreParser::INT, 0);
}

std::vector<AudioScoreParser::StatementContext *> AudioScoreParser::LoopStmtContext::statement() {
  return getRuleContexts<AudioScoreParser::StatementContext>();
}

AudioScoreParser::StatementContext* AudioScoreParser::LoopStmtContext::statement(size_t i) {
  return getRuleContext<AudioScoreParser::StatementContext>(i);
}


size_t AudioScoreParser::LoopStmtContext::getRuleIndex() const {
  return AudioScoreParser::RuleLoopStmt;
}

void AudioScoreParser::LoopStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoopStmt(this);
}

void AudioScoreParser::LoopStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoopStmt(this);
}


std::any AudioScoreParser::LoopStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AudioScoreVisitor*>(visitor))
    return parserVisitor->visitLoopStmt(this);
  else
    return visitor->visitChildren(this);
}

AudioScoreParser::LoopStmtContext* AudioScoreParser::loopStmt() {
  LoopStmtContext *_localctx = _tracker.createInstance<LoopStmtContext>(_ctx, getState());
  enterRule(_localctx, 8, AudioScoreParser::RuleLoopStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    match(AudioScoreParser::T__5);
    setState(54);
    match(AudioScoreParser::INT);
    setState(55);
    match(AudioScoreParser::T__3);
    setState(59);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 962) != 0)) {
      setState(56);
      statement();
      setState(61);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(62);
    match(AudioScoreParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PlayStmtContext ------------------------------------------------------------------

AudioScoreParser::PlayStmtContext::PlayStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AudioScoreParser::PlayStmtContext::ID() {
  return getToken(AudioScoreParser::ID, 0);
}


size_t AudioScoreParser::PlayStmtContext::getRuleIndex() const {
  return AudioScoreParser::RulePlayStmt;
}

void AudioScoreParser::PlayStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPlayStmt(this);
}

void AudioScoreParser::PlayStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPlayStmt(this);
}


std::any AudioScoreParser::PlayStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AudioScoreVisitor*>(visitor))
    return parserVisitor->visitPlayStmt(this);
  else
    return visitor->visitChildren(this);
}

AudioScoreParser::PlayStmtContext* AudioScoreParser::playStmt() {
  PlayStmtContext *_localctx = _tracker.createInstance<PlayStmtContext>(_ctx, getState());
  enterRule(_localctx, 10, AudioScoreParser::RulePlayStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    match(AudioScoreParser::T__6);
    setState(65);
    match(AudioScoreParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NoteStmtContext ------------------------------------------------------------------

AudioScoreParser::NoteStmtContext::NoteStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AudioScoreParser::NoteStmtContext::NOTE() {
  return getToken(AudioScoreParser::NOTE, 0);
}

tree::TerminalNode* AudioScoreParser::NoteStmtContext::INT() {
  return getToken(AudioScoreParser::INT, 0);
}

tree::TerminalNode* AudioScoreParser::NoteStmtContext::DUR() {
  return getToken(AudioScoreParser::DUR, 0);
}


size_t AudioScoreParser::NoteStmtContext::getRuleIndex() const {
  return AudioScoreParser::RuleNoteStmt;
}

void AudioScoreParser::NoteStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNoteStmt(this);
}

void AudioScoreParser::NoteStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNoteStmt(this);
}


std::any AudioScoreParser::NoteStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AudioScoreVisitor*>(visitor))
    return parserVisitor->visitNoteStmt(this);
  else
    return visitor->visitChildren(this);
}

AudioScoreParser::NoteStmtContext* AudioScoreParser::noteStmt() {
  NoteStmtContext *_localctx = _tracker.createInstance<NoteStmtContext>(_ctx, getState());
  enterRule(_localctx, 12, AudioScoreParser::RuleNoteStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    match(AudioScoreParser::NOTE);
    setState(68);
    match(AudioScoreParser::INT);
    setState(69);
    match(AudioScoreParser::DUR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RestStmtContext ------------------------------------------------------------------

AudioScoreParser::RestStmtContext::RestStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AudioScoreParser::RestStmtContext::DUR() {
  return getToken(AudioScoreParser::DUR, 0);
}


size_t AudioScoreParser::RestStmtContext::getRuleIndex() const {
  return AudioScoreParser::RuleRestStmt;
}

void AudioScoreParser::RestStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRestStmt(this);
}

void AudioScoreParser::RestStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRestStmt(this);
}


std::any AudioScoreParser::RestStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AudioScoreVisitor*>(visitor))
    return parserVisitor->visitRestStmt(this);
  else
    return visitor->visitChildren(this);
}

AudioScoreParser::RestStmtContext* AudioScoreParser::restStmt() {
  RestStmtContext *_localctx = _tracker.createInstance<RestStmtContext>(_ctx, getState());
  enterRule(_localctx, 14, AudioScoreParser::RuleRestStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    match(AudioScoreParser::T__7);
    setState(72);
    match(AudioScoreParser::DUR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void AudioScoreParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  audioscoreParserInitialize();
#else
  ::antlr4::internal::call_once(audioscoreParserOnceFlag, audioscoreParserInitialize);
#endif
}
