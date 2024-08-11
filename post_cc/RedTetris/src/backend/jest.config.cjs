module.exports = {
	collectCoverage: true,
	collectCoverageFrom: [
	  '**/*.{js,jsx}',
	  '!**/node_modules/**',
	  '!**/coverage/**',
	  '!**/vendor/**'
	],
	coverageThreshold: {
	  global: {
		statements: 70,
		branches: 50,
		functions: 70,
		lines: 70
	  }
	},
	coverageReporters: ['json', 'text', 'lcov', 'clover']
  };
