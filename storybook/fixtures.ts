import { buildClientSchema, printSchema } from 'graphql'
import apolloStorybookDecorator from 'apollo-storybook-react'
import faker from 'faker'
import { MockList } from 'graphql-tools';
import { description } from '../src/Profile/components/ProfileInfo.bs';

const graphqlIntrospectionSchema = require('../graphql_schema.json')

const graphqlSchemaObj = buildClientSchema(graphqlIntrospectionSchema.data)
export const typeDefs = printSchema(graphqlSchemaObj)

const featured = "https://source.unsplash.com/featured";

const featuredWithOptions = (width, q = 80, fm = "jpg", fit = "max") => `${featured}?w=${width}&q=${q}&fm=${fm}&fit=${fit}}`

const baseMocks = {
    Query: () => ({
        photos: () => new MockList(18),
    }),
    Photo: () => ({
        id: () => faker.random.uuid(),
        likes: () => faker.random.number(400),
        description: () => faker.lorem.paragraphs(5),
    }),
    PhotoLocation: () => ({
        city: () => faker.address.city(),
        country: () => faker.address.country(),
    }),
    PhotoUrls: (args) => ({
        raw: () => featured,
        full: () => `${featured}?q=80&fm=jpg`,
        regular: () => featuredWithOptions(1080),
        small: () => featured + `/?${"plants," + args.id()}`,
        thumb: () => featuredWithOptions(200),
    }),
    User: () => ({
        name: faker.internet.userName(),
        username: faker.internet.userName(),
        bio: faker.lorem.lines(5),
        total_photos: faker.random.number(100),
        followers_count: faker.random.number(300),
        following_count: faker.random.number(300),
        portfolio_url: faker.internet.url()
    }),
    UserProfileImage: () => ({
        small: () => featuredWithOptions(400)
    }),
};

export const apolloMocks = (mocks = {}) => apolloStorybookDecorator({
    typeDefs,
    mocks: { ...baseMocks, ...mocks },
    resolverValidationOptions: {
        requireResolversForResolveType: false,
    },
})
